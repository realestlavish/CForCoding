import uuid
from langchain.tools import tool
from RAG import vector_db_setup
from deepagents.backends import StateBackend

backend= StateBackend();

@tool(parse_docstring=True)
def search_documentation(query :str) -> str:
    """Search LangChain documentation and save matching chunks to the agent filesystem.

    Args:
        query: Natural language search query.

    Returns:
        File paths where retrieved chunks were saved under /retrieved/.
    """
    retrieved_docs=vectorDB.similarity_search(query,k=5)
    batch_id=uuid.uuid4().hex[:8]
    uploaded_data:list[tuple[str,bytes]] =[]
    saved_paths:list[str] =[]
    
    for index,doc in enumerate(retrieved_docs,start=1):
        path=f"/retrieved/{batch_id}/chunk_{index}.md"
        content=(
            f"#Source :{doc.metadata.get('source','unknown')}\n\n"\
            f"{doc.page_content}"
        )
        uploaded_data.append((path, content.encode("utf-8")))
        saved_paths.append(path)
        
    backend.upload_files(uploaded_data)
    return (
        f"Saved {len(saved_paths)} documentation chunks:\n"
        + "\n".join(saved_paths)
    )

# uuid = generates a random hexadecimal String to be saved as path.
# langchain.tool = wraps the function to be used as tool autonomously.
# statebackend= used to monitor the current state of the program.

# the parse docstring is used to give context about the agent to LLM, so it knows when to use the agent and for which tasks.
# similarity search is used and 2 args(query and k are passed). K tells the search function to return the top 5 result from the search according to query.
# batch_id is a unique id for each search
# uploaded_data is empty data type to store the retrieved docs, the data is stored as list of pair of [str, bytes] in which the str is path of the data and the bytes is data in raw binary form.
# saved_paths is used to store paths of data
# enumerate return 2 things, the docs and the index which is used to append in uploaded_data.
 