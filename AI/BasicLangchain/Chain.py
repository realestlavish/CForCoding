from dotenv import load_dotenv
load_dotenv()
from pydantic import BaseModel, Field
from langchain_core.runnables import chain
from langchain_core.prompts import PromptTemplate
from langchain.chat_models import init_chat_model
from langchain_core.output_parsers import JsonOutputParser

model = init_chat_model(
    model = "gemini-2.5-flash",
    model_provider = "google_genai"
)

class MathInput(BaseModel):
    a: int = Field(..., description="First number to add")
    b: int = Field(..., description="Second number to add")
@chain 
def two_add(inputs: MathInput):
    return inputs.a + inputs.b
@chain 
def multiply_by_two(x):
    return x * 2

@chain 
def raise_to_power_of_two(x):
    return x ** 2
structured_model= model.with_structured_output(MathInput)

prompt= PromptTemplate.from_template(' Extract the 2 numbers from the Request and Return them STRICTLY in JSON FORMAT ONLY . '
                                     'Request: {user_request}')

chain1 =prompt | structured_model | two_add | multiply_by_two | raise_to_power_of_two

result = chain1.invoke({"user_request": "I have 3 apples and 4 oranges. I want to add them, multiply by 2."})
print(result)