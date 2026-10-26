import { useDispatch, useSelector } from 'react-redux'
import { setQuery, submitSearch } from '../redux/features/searchSlice'

function SearchBar() {
  const dispatch = useDispatch()
  const query = useSelector((state) => state.search.query)

  function handleSubmit(event) {
    event.preventDefault()
    dispatch(submitSearch())
  }

  return (
    <form className="search-form" onSubmit={handleSubmit} role="search">
      <label className="visually-hidden" htmlFor="media-search">
        Search for photos or GIFs
      </label>
      <span className="search-icon" aria-hidden="true">
        ⌕
      </span>
      <input
        id="media-search"
        type="search"
        value={query}
        onChange={(event) => dispatch(setQuery(event.target.value))}
        placeholder="Try “mountain lake” or “abstract shapes”"
      />
      <button className="button button-primary" type="submit">
        Search
      </button>
    </form>
  )
}

export default SearchBar
