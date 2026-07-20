from dotenv import load_dotenv
load_dotenv()
from langchain_core.prompts import ChatPromptTemplate, MessagesPlaceholder,SystemMessagePromptTemplate,HumanMessagePromptTemplate
from langchain_core.runnables.history import RunnableWithMessageHistory
from langchain_core.chat_history import InMemoryChatMessageHistory
from langchain.chat_models import init_chat_model

# 1. Initialize Model (Using the same pattern as Module 1)
model = init_chat_model(
    model="gemini-2.5-flash",
    model_provider="google_genai"
)

system_prompt="You are a helpful assistant."

# 2. Define Prompt with a 'history' placeholder
prompt = ChatPromptTemplate.from_messages([
    SystemMessagePromptTemplate.from_template(system_prompt),
    MessagesPlaceholder(variable_name="history"), # This is where memory is injected
    HumanMessagePromptTemplate.from_template("{input}"),
])

# 3. Create the basic chain
chain = prompt | model

# 4. Setup in-memory store for chat histories
store = {}
def get_chat_history(session_id: str) -> InMemoryChatMessageHistory:
    if session_id not in store:
        # if session ID doesn't exist, create a new chat history
        store[session_id] = InMemoryChatMessageHistory()
    return store[session_id]


# 5. Wrap the chain with RunnableWithMessageHistory
with_message_history = RunnableWithMessageHistory(
    chain,
    get_chat_history,
    input_messages_key="input",
    history_messages_key="history",
)

# 6. Test with a session ID
config = {"configurable": {"session_id": "session1"}}

# Interaction 1
response1 = with_message_history.invoke({"input": "Hi! My name is Lavish."}, config=config)
print(f"Assistant: {response1.content}")

# Interaction 2
response2 = with_message_history.invoke({"input": "What is my name?"}, config=config)
print(f"Assistant: {response2.content}")