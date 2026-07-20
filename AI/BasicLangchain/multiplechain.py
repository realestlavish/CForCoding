from dotenv import load_dotenv
load_dotenv()
from langchain_ollama import ChatOllama 
from langchain_core.prompts import ChatPromptTemplate, PromptTemplate
from langchain.chat_models import init_chat_model
from langchain_core.output_parsers import StrOutputParser

fallback_model = ChatOllama(model="gemma4", model_provider="ollama")
primary_model = init_chat_model(model="gemini-2.5-flash", model_provider="google_genai")

model = primary_model.with_fallbacks([fallback_model])

summary_prompt = ChatPromptTemplate.from_template('Write a Short summary about the Car {car_name} in maximum 50 words.')
summary_chain=summary_prompt | model | StrOutputParser()
    
one_word_prompt =ChatPromptTemplate.from_template('Write one word about the car based on the Summary: {summary}')
one_word_chain=one_word_prompt | model | StrOutputParser()

main_chain= {'summary' :summary_chain} | one_word_chain

result = main_chain.invoke({"car_name": "Tata Nano "})
print(result)