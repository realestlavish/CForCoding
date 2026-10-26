import { useDispatch, useSelector } from 'react-redux'
import { saveMedia } from '../redux/features/collectionSlice'

function ResultCard({ item }) {
  const dispatch = useDispatch()
  const isSaved = useSelector((state) =>
    state.collection.some((savedItem) => savedItem.id === item.id),
  )

  return (
    <article className="media-card">
      <a
        className={`media-preview media-preview-${item.type}`}
        href={item.pageUrl}
        rel="noreferrer"
        target="_blank"
        aria-label={`Open ${item.title} on ${item.source}`}
      >
        <img alt={item.title} loading="lazy" src={item.thumbnail || item.url} />
        <span className="source-badge">{item.source}</span>
      </a>
      <div className="media-card-footer">
        <p title={item.title}>{item.title || 'Untitled media'}</p>
        <button
          aria-label={isSaved ? 'Already saved' : `Save ${item.title}`}
          className={`save-button${isSaved ? ' is-saved' : ''}`}
          disabled={isSaved}
          onClick={() => dispatch(saveMedia(item))}
          type="button"
        >
          {isSaved ? 'Saved' : '＋ Save'}
        </button>
      </div>
    </article>
  )
}

export default ResultCard
