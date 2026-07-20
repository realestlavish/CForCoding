from dotenv import load_dotenv
load_dotenv()
from langchain_openai import OpenAIEmbeddings
import getpass
import os
os.environ["LANGSMITH_TRACING"] = "true"
import requests
from langchain_core.documents import Document
from langchain_core.vectorstores import InMemoryVectorStore
from langchain_openai import OpenAIEmbeddings
from langchain_text_splitters import RecursiveCharacterTextSplitter

#Load the Data

DOCS_BASE = "https://docs.langchain.com"

# Curated LangChain OSS pages for this tutorial. Expand this list or parse
# URLs from https://docs.langchain.com/llms.txt to index more of the site.
DOC_PATHS = [
    "oss/python/langchain/agents",
    "oss/python/deepagents/rag",
    "oss/python/langchain/tools",
    "oss/python/langchain/models",
    "oss/python/langchain/retrieval",
    "oss/python/langchain/knowledge-base",
    "oss/python/langchain/middleware",
    "oss/python/deepagents/overview",
    "oss/python/deepagents/subagents",
    "oss/python/deepagents/streaming",
    "oss/python/deepagents/frontend/subagent-streaming",
    "oss/python/deepagents/backends",
    "oss/python/langgraph/overview",
    "oss/python/langgraph/quickstart",
]

def load_langchain_documentation(doc_paths:list[str] | None=None ) -> list[Document]:
    paths=DOC_PATHS or doc_paths
    docs:list[Document] =[]
    for path in paths:
        url= f"{DOCS_BASE}/{path}.md"
        try:
            response= requests.get(url,timeout=20)
            response.raise_for_status()
        except requests.RequestException:
            continue
        source=f"{DOCS_BASE}/{path}"
        docs.append(
            Document(page_content=response.text,metadata={"source":source})
        )
    return docs

docs=load_langchain_documentation()
print(f"loaded {len(docs)} pages of documentation")


#Splitting the Data using splitter
text_splitter = RecursiveCharacterTextSplitter(chunk_size=1000, chunk_overlap=200)
splitted_docs = text_splitter.split_documents(docs)
print(f"Split documentation into {len(splitted_docs)} chunks.")

#Embedding the chunks (capturing the literal model)
embeddings = OpenAIEmbeddings(model="text-embedding-3-large")

#VectorDB
vectorDB=InMemoryVectorStore(embeddings)
vectorDB.add_documents(documents=splitted_docs)
print(f"Indexed {len(splitted_docs)} chunks.")

#now, data is stored in vector DB in chunks.
