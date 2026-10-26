import { useDispatch, useSelector } from 'react-redux'
import CollectionCard from '../components/CollectionCard'
import { clearCollection } from '../redux/features/collectionSlice'

function CollectionPage() {
  const dispatch = useDispatch()
  const collection = useSelector((state) => state.collection)

  return (
    <section className="collection-page">
      <div className="page-heading">
        <div>
          <p className="eyebrow">Your personal gallery</p>
          <h1>Collection</h1>
          <p className="hero-description">
            {collection.length
              ? `${collection.length} saved ${collection.length === 1 ? 'item' : 'items'}`
              : 'The media you save will be waiting here.'}
          </p>
        </div>
        {collection.length > 0 && (
          <button
            className="button button-secondary"
            onClick={() => dispatch(clearCollection())}
            type="button"
          >
            Clear collection
          </button>
        )}
      </div>
      {collection.length ? (
        <div className="media-grid collection-grid">
          {collection.map((item) => <CollectionCard item={item} key={item.id} />)}
        </div>
      ) : (
        <div className="empty-state collection-empty">
          <span className="empty-state-icon" aria-hidden="true">♡</span>
          <h2>A space for your favorites</h2>
          <p>Save photos and GIFs from Search to start your collection.</p>
        </div>
      )}
    </section>
  )
}

export default CollectionPage
