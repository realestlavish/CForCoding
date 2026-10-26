import axios from 'axios'

const requiredKey = (keyName) => {
  const key = import.meta.env[keyName]
  if (!key) {
    throw new Error(`Missing ${keyName} environment variable.`)
  }
  return key
}

export async function getPhotos(query, page = 1, perPage = 24) {
  const response = await axios.get('https://api.unsplash.com/search/photos', {
    params: { query, page, per_page: perPage },
    headers: { Authorization: `Client-ID ${requiredKey('VITE_UNSPLASH_KEY')}` },
  })
  return response.data.results
}

export async function getGIFs(query, limit = 24) {
  const response = await axios.get('https://api.giphy.com/v1/gifs/search', {
    params: {
      q: query,
      api_key: requiredKey('VITE_GIPHY_KEY'),
      limit,
    },
  })
  return response.data.data
}

export const getGIF = getGIFs
