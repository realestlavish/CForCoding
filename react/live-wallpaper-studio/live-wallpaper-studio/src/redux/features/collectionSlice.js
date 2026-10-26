import { createSlice } from '@reduxjs/toolkit'

const STORAGE_KEY = 'wallpaper-studio-collection'

function readCollection() {
  const savedCollection = localStorage.getItem(STORAGE_KEY)
  if (!savedCollection) return []

  try {
    const collection = JSON.parse(savedCollection)
    if (Array.isArray(collection)) return collection
    console.error('Saved media collection is not an array.')
    return []
  } catch (error) {
    console.error('Could not read the saved media collection.', error)
    return []
  }
}

const collectionSlice = createSlice({
  name: 'collection',
  initialState: readCollection(),
  reducers: {
    saveMedia(state, action) {
      if (!state.some((item) => item.id === action.payload.id)) {
        state.push(action.payload)
      }
    },
    removeMedia(state, action) {
      return state.filter((item) => item.id !== action.payload)
    },
    clearCollection() {
      return []
    },
  },
})

export const collectionStorageKey = STORAGE_KEY
export const { saveMedia, removeMedia, clearCollection } = collectionSlice.actions
export default collectionSlice.reducer