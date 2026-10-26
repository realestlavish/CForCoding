import { useDispatch } from 'react-redux'
import { removeMedia } from '../redux/features/collectionSlice'

function CollectionCard({ item }) {
  const dispatch = useDispatch()

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
          aria-label={`Remove ${item.title} from collection`}
          className="save-button remove-button"
          onClick={() => dispatch(removeMedia(item.id))}
          type="button"
        >
          Remove
        </button>
      </div>
    </article>
  )
}

export default CollectionCard
