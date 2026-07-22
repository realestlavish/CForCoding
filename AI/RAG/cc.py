from langchain_ollama import ChatOllama
from langchain_core.tools import tool

@tool
def add(a: int, b: int) -> int:
    """Add two integers."""
    return a + b

model = ChatOllama(model="qwen3-coder:30b")
model = model.bind_tools([add])

response = model.invoke("What is 5 + 7?")

print(response)
print(response.tool_calls)