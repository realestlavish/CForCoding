import TextEnter from './textEnter'

const Section1 = ({toAddNote}) => {
  return (
    <div className='h-screen w-screen'>
        <TextEnter toAddNote={toAddNote} />
    </div>
  )
}

export default Section1