#Standalone model with Conversation
from dotenv import load_dotenv
import os

load_dotenv()

from langchain.chat_models import init_chat_model
from langchain.messages import SystemMessage, HumanMessage, AIMessage  

model = init_chat_model(
    model="gemini-2.5-flash",
    model_provider="google_genai",
    max_retries=5
)
conversation = [
    SystemMessage(content="You are a helpful assistant."),
    HumanMessage(content="information about twr supercat "),
    AIMessage(content="The TWR Supercat is a high-performance catamaran designed for speed and agility. It features a lightweight hull, advanced sail design, and cutting-edge materials to maximize performance on the water. The Supercat is popular among competitive sailors and enthusiasts looking for an exhilarating sailing experience."),
    HumanMessage(content="What is the maximum horsepower,speed and torque of the TWR Supercat?"),
]
#it shows the answers being streamed in chunks, which is useful for long responses or when you want to display the output as it is generated.
for chunk in  model.stream(conversation):
    print(chunk, end="", flush=True)

print(ans.content)

