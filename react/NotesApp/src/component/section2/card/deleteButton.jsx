const DeleteButton = ({toDeleteNote}) => {
  return (
    <button onClick={toDeleteNote} className='self-start rounded-lg bg-red-100 px-3 py-1.5 text-sm font-medium text-red-700 transition-colors hover:bg-red-200 focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-red-500'>
      Delete
    </button>
  )
}

export default DeleteButton
