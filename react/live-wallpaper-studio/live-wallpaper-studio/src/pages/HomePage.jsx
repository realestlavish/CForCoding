import { useSelector } from 'react-redux'
import ResultGrid from '../components/ResultGrid'
import SearchBar from '../components/SearchBar'
import Tabs from '../components/Tabs'

function HomePage() {
  const { submittedQuery, activeTab } = useSelector((state) => state.search)
  const countLabel = activeTab === 'gifs' ? 'GIFs' : 'Photos'

  return (
    <section className="home-page">
      <div className="hero-copy">
        <p className="eyebrow">Your visual inspiration library</p>
        <h1>Find the feeling.<br /><span>Save the frame.</span></h1>
        <p className="hero-description">
          Search a world of imagery and little moments worth keeping.
        </p>
      </div>
      <SearchBar />
      <Tabs />
      <div className="results-heading">
        <h2>{submittedQuery ? `Results for “${submittedQuery}”` : 'Explore media'}</h2>
        <span>{submittedQuery ? countLabel : 'Photos · GIFs'}</span>
      </div>
      <ResultGrid />
    </section>
  )
}

export default HomePage
