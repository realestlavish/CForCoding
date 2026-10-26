import { useEffect } from 'react'
import { useDispatch, useSelector } from 'react-redux'
import { getGIFs, getPhotos } from '../api/mediaApi'
import {
  setError,
  setLoading,
  setResults,
} from '../redux/features/searchSlice'
import ResultCard from './ResultCard'

function normalizeMedia(item, type) {
  if (type === 'photos') {
    return {
      id: `photo-${item.id}`,
      type,
      url: item.urls?.regular,
      thumbnail: item.urls?.small,
      title: item.alt_description || item.description || 'Unsplash photo',
      source: 'Unsplash',
      pageUrl: item.links?.html || item.urls?.regular,
    }
  }

  const media = item.images?.original
  const thumbnail = item.images?.fixed_width || item.images?.original
  return {
    id: `gif-${item.id}`,
    type,
    url: media?.url,
    thumbnail: thumbnail?.url,
    title: item.title || 'Giphy GIF',
    source: 'Giphy',
    pageUrl: item.url,
  }
}

function ResultGrid() {
  const dispatch = useDispatch()
  const { activeTab, submittedQuery, results, loading, error } = useSelector(
    (state) => state.search,
  )

  useEffect(() => {
    if (!submittedQuery) {
      dispatch(setResults([]))
      dispatch(setError(null))
      dispatch(setLoading(false))
      return undefined
    }

    let cancelled = false
    dispatch(setLoading(true))
    dispatch(setError(null))

    const request = activeTab === 'photos'
      ? getPhotos(submittedQuery)
      : getGIFs(submittedQuery)

    request
      .then((items) => {
        if (!cancelled) {
          dispatch(setResults(items.map((item) => normalizeMedia(item, activeTab))))
        }
      })
      .catch((requestError) => {
        if (!cancelled) {
          dispatch(setResults([]))
          dispatch(setError(requestError.message || 'Unable to load media.'))
        }
      })
      .finally(() => {
        if (!cancelled) dispatch(setLoading(false))
      })

    return () => {
      cancelled = true
    }
  }, [activeTab, dispatch, submittedQuery])

  if (!submittedQuery) {
    return (
      <div className="empty-state">
        <span className="empty-state-icon" aria-hidden="true">✳</span>
        <h2>Find your next favorite</h2>
        <p>Search for a mood, place, or idea to explore free media.</p>
      </div>
    )
  }

  if (loading) {
    return <p className="status-message" role="status">Finding inspiration…</p>
  }

  if (error) {
    return (
      <div className="status-message error-message" role="alert">
        <strong>We couldn’t load these results.</strong>
        <span>{error}</span>
        <span>Check your provider API key and try again.</span>
      </div>
    )
  }

  if (results.length === 0) {
    return (
      <div className="empty-state compact-empty">
        <h2>No results found</h2>
        <p>Try a different search phrase.</p>
      </div>
    )
  }

  return (
    <div className="media-grid">
      {results.map((item) => <ResultCard item={item} key={item.id} />)}
    </div>
  )
}

export default ResultGrid
