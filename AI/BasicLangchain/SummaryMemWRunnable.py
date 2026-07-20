from dotenv import load_dotenv
load_dotenv()
from langchain_core.prompts import ChatPromptTemplate, SystemMessagePromptTemplate,HumanMessagePromptTemplate
from langchain_core.runnables.history import RunnableWithMessageHistory
from pydantic import BaseModel, Field
from langchain_core.chat_history import BaseChatMessageHistory,BaseMessage
from langchain_core.messages import SystemMessage
from langchain_core.runnables.utils import ConfigurableFieldSpec
from langchain_core.language_models.chat_models import BaseChatModel
from langchain.chat_models import init_chat_model

# 1. Initialize Model (Using the same pattern as Module 1)
llm = init_chat_model(
    model="gemini-2.5-flash",
    model_provider="google_genai"
)

query = ChatPromptTemplate.from_messages([("human", "{query}")])

class ConversationSummaryMessageHistory(BaseChatMessageHistory, BaseModel):
    messages: list[BaseMessage] = Field(default_factory=list)
    llm: BaseChatModel

    def __init__(self, llm: BaseChatModel):
        super().__init__(llm=llm)

    def add_messages(self, messages: list[BaseMessage]) -> None:
        """Add messages to the history, removing any messages beyond
        the last `k` messages.
        """
        self.messages.extend(messages)
        # construct the summary chat messages
        summary_prompt = ChatPromptTemplate.from_messages([
            SystemMessagePromptTemplate.from_template(
                "Given the existing conversation summary and the new messages, "
                "generate a new summary of the conversation. Ensuring to maintain "
                "as much relevant information as possible."
            ),
            HumanMessagePromptTemplate.from_template(
                "Existing conversation summary:\n{existing_summary}\n\n"
                "New messages:\n{messages}"
            )
        ])
        # format the messages and invoke the LLM
        new_summary = self.llm.invoke(
            summary_prompt.format_messages(existing_summary=self.messages, messages=messages)
        )
        # replace the existing history with a single system summary message 
        self.messages = [SystemMessage(content=new_summary.content)]

    def clear(self) -> None:
        """Clear the history."""
        self.messages = []
        
pipeline = query | llm
        
chat_map = {}
def get_chat_history(session_id: str, llm: BaseChatModel) -> ConversationSummaryMessageHistory:
    if session_id not in chat_map:
        # if session ID doesn't exist, create a new chat history
        chat_map[session_id] = ConversationSummaryMessageHistory(llm=llm)
    # return the chat history
    return chat_map[session_id]


pipeline_with_history = RunnableWithMessageHistory(
    pipeline,
    get_session_history=get_chat_history,
    input_messages_key="query",
    history_messages_key="history",
    history_factory_config=[
        ConfigurableFieldSpec(
            id="session_id",
            annotation=str,
            name="Session ID",
            description="The session ID to use for the chat history",
            default="id_default",
        ),
        ConfigurableFieldSpec(
            id="llm",
            annotation=BaseChatModel,
            name="LLM",
            description="The LLM to use for the conversation summary",
            default=llm,
        )
    ]
)

pipeline_with_history.invoke(
    {"query": "What is my name again?"},
    config={"configurable": {"session_id": "id_123", "llm": llm}}
)

# Interaction 1
response1 = pipeline_with_history.invoke({"query": "Hi! My name is Lavish."}, config=ConfigurableFieldSpec)
print(f"Assistant: {response1.content}")

# Interaction 2
response2 = pipeline_with_history.invoke({"query": "What is my name?"}, config=ConfigurableFieldSpec)
print(f"Assistant: {response2.content}")