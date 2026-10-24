import { useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'
import { Decrement, Increment, IncrementByAmount } from './stores/counterSlice.js'
import './App.css'

const App = () => {
  const dispatch = useDispatch()
  const count = useSelector((state) => state.counter.value)
  const [amount, setAmount] = useState('1')
  const parsedAmount = Number(amount)
  const isValidAmount = Number.isInteger(parsedAmount) && parsedAmount >= 1

  return (
    <main className="counter">
      <h1>Counter</h1>
      <output className="counter__value" aria-live="polite">{count}</output>
      <div className="counter__controls">
        <button
          className="counter__button"
          type="button"
          onClick={() => dispatch(Increment())}
        >
          Increment
        </button>
        <button
          className="counter__button"
          type="button"
          onClick={() => dispatch(Decrement())}
        >
          Decrement
        </button>
        <form
          className="counter__amount-form"
          onSubmit={(event) => {
            event.preventDefault()
            if (isValidAmount) {
              dispatch(IncrementByAmount(parsedAmount))
            }
          }}
        >
          <label htmlFor="increment-amount">Amount</label>
          <input
            id="increment-amount"
            type="number"
            min="1"
            step="1"
            required
            value={amount}
            onChange={(event) => setAmount(event.target.value)}
          />
          <button className="counter__button" type="submit" disabled={!isValidAmount}>
            Increment by amount
          </button>
        </form>
      </div>
    </main>
  )
}

export default App