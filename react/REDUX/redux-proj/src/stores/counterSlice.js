import { createSlice } from '@reduxjs/toolkit'

const counterSlice = createSlice({
  name: 'counter',
  initialState: {
    value: 0,
  },
  reducers: {
    Increment: (state) => {
      state.value += 1
    },
    Decrement: (state) => {
      state.value -= 1
    },
    IncrementByAmount: (state, action) => {
      state.value += action.payload
    },
  },
})

export const counterReducer = counterSlice.reducer
export const { Increment, Decrement, IncrementByAmount } = counterSlice.actions