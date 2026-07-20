from dotenv import load_dotenv
load_dotenv()
from langchain_core.output_parsers import StrOutputParser
from langchain_core.prompts import PromptTemplate
from langchain.chat_models import init_chat_model
from langchain_core.runnables import chain

model= init_chat_model(
    model="gemini-2.5-flash",
    model_provider="google_genai"
)
@chain
def text_processor(data):
    return data.lower()

prompt=PromptTemplate.from_template('Remove the Excessive Slang and Rewrite the paragraph professionally {paragraph}')

chain1= text_processor|prompt|model| StrOutputParser()

data = 'YO wassup dude, how u doing, how u been yo, lets kick it today and how is the huzz doing'
print(chain1.invoke(data))
