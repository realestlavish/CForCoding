import Section2 from "./component/section2/card/Section2"
import Section1 from "./component/Section1/Section1"
import { useState } from "react"

const initialNotes = [
    {
      title: "Plan the week",
      description: "Choose three priorities to focus on this week.",
    },
    {
      title: "Buy groceries",
      description: "Pick up fruit, vegetables, bread, and coffee.",
    },
    {
      title: "Read more",
      description: "Spend 20 minutes reading before bed tonight.",
    },
]

const App = () => {
  const [notes, setNotes] = useState(initialNotes)

  const addNewNote = (newNote) => {
    setNotes((currentNotes) => [...currentNotes, newNote])
  }

const deleteNote = (targetIdx) => {
  setNotes((currentNotes) => currentNotes.filter((note, index) => index !== targetIdx));
}

  return (
    <div className="flex justify-around bg-amber-300">
      <Section1 toAddNote={addNewNote} />
      <div aria-orientation="vertical" role="separator" className="w-px shrink-0 self-stretch bg-black" />
      <Section2 notes={notes} toDeleteNote={deleteNote}/>
    </div>
  )
}

export default App