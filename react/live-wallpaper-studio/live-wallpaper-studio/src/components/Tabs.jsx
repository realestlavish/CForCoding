import { useDispatch, useSelector } from 'react-redux'
import { setActiveTab } from '../redux/features/searchSlice'

const tabs = [
  { id: 'photos', label: 'Photos' },
  { id: 'gifs', label: 'GIFs' },
]

function Tabs() {
  const dispatch = useDispatch()
  const activeTab = useSelector((state) => state.search.activeTab)

  return (
    <div className="media-tabs" role="tablist" aria-label="Media type">
      {tabs.map((tab) => (
        <button
          aria-selected={activeTab === tab.id}
          className={`media-tab${activeTab === tab.id ? ' is-active' : ''}`}
          key={tab.id}
          onClick={() => dispatch(setActiveTab(tab.id))}
          role="tab"
          type="button"
        >
          {tab.label}
        </button>
      ))}
    </div>
  )
}

export default Tabs
