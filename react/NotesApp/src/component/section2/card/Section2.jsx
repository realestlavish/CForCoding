import Card from './card.jsx'

const Section2 = ({ notes = [], toDeleteNote }) => {
  return (
    <div className='h-full w-full'>
      <h4 className='mb-6 ml-85 mt-5  text-2xl font-bold text-gray-900'>Notes</h4>
      {notes.map((note, index) => (
        <Card
          key={`${note.title}-${index}`}
          title={note.title}
          description={note.description}
          toDeleteNote={() => toDeleteNote(index)}
        />
      ))}
    </div>
  )
}

export default Section2