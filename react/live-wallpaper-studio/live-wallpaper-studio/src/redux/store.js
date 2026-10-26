import { configureStore } from '@reduxjs/toolkit'
import collectionReducer, {
  clearCollection,
  collectionStorageKey,
  removeMedia,
  saveMedia,
} from './features/collectionSlice'
import searchReducer from './features/searchSlice'

const collectionPersistence = (storeApi) => (next) => (action) => {
  const result = next(action)

  if (saveMedia.match(action) || removeMedia.match(action)) {
    localStorage.setItem(
      collectionStorageKey,
      JSON.stringify(storeApi.getState().collection),
    )
  } else if (clearCollection.match(action)) {
    localStorage.removeItem(collectionStorageKey)
  }

  return result
}

export const store = configureStore({
  reducer: {
    search: searchReducer,
    collection: collectionReducer,
  },
  middleware: (getDefaultMiddleware) =>
    getDefaultMiddleware().concat(collectionPersistence),
})