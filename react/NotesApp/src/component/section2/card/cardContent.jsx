const CardContent = ({ title, description }) => {
  return (
    <div className='mb-5'>
      <h2 className='text-xl font-bold leading-tight text-gray-900'>{title}</h2>
      <p className='mt-2 text-sm leading-relaxed text-gray-600'>{description}</p>
    </div>
  )
}

export default CardContent
