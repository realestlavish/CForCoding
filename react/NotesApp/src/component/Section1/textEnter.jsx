import { useState } from 'react'

const TextEnter = ({ toAddNote }) => {
  const [title, setTitle] = useState('')
  const [description, setDescription] = useState('')

  const submitHandler = (event) => {
    event.preventDefault()
    if (!title.trim() || !description.trim()) return

    toAddNote({ title: title.trim(), description: description.trim() })
    setTitle('')
    setDescription('')
}
  return (
    <form className='flex w-full flex-col gap-4 p-10' onSubmit={submitHandler}>
        <input
          className='w-full rounded-lg border-0 bg-white px-4 py-3 text-gray-800 shadow-sm placeholder:text-gray-400 focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-blue-500'
          type="text"
          placeholder='Enter the task title'
          value={title}
          onChange={(event) => setTitle(event.target.value)}
          required
        />
        <textarea
          className='min-h-32 w-full resize-y rounded-lg border-0 bg-white px-4 py-3 text-gray-800 shadow-sm placeholder:text-gray-400 focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-blue-500'
          placeholder='Enter the description'
          value={description}
          onChange={(event) => setDescription(event.target.value)}
          required
        />
        <div>
        <button type="submit" className="m-10 ml-75 cursor-pointer rounded-md border-0 bg-blue-600 px-4 py-2 font-[inherit] text-white transition-colors duration-150 hover:bg-blue-700 focus-visible:outline-3 focus-visible:outline-offset-2 focus-visible:outline-blue-300"> Add Notes</button>
    </div>
    </form>
  )
}

export default TextEnter