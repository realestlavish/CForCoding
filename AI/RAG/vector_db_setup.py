from dotenv import load_dotenv
load_dotenv()
import getpass
import os
import requests
from langchain_core.documents import Document
from langchain_core.vectorstores import InMemoryVectorStore
# Newer LangChain: embeddings exposed from langchain.embeddings
from langchain_huggingface import HuggingFaceEmbeddings
from langchain_ollama import ChatOllama
from langchain_text_splitters import RecursiveCharacterTextSplitter


print("LANGSMITH_API_KEY =", os.getenv("LANGSMITH_API_KEY"))
print("LANGCHAIN_API_KEY =", os.getenv("LANGCHAIN_API_KEY"))
print("LANGCHAIN_TRACING_V2 =", os.getenv("LANGCHAIN_TRACING_V2"))