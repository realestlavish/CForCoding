import CardContent from './cardContent.jsx'
import DeleteButton from './deleteButton.jsx'

const Card = ({ title, description, toDeleteNote }) => {
  return (
    <article className='m-2 flex aspect-square w-64 max-w-full flex-col justify-between rounded-xl bg-white p-5 shadow-md transition-shadow hover:shadow-lg'>
      <CardContent title={title} description={description} />
      <DeleteButton toDeleteNote={toDeleteNote} />
    </article>
  )
}

export default Card
