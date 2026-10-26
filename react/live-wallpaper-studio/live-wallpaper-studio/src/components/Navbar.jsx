import { NavLink } from 'react-router-dom'

function Navbar() {
  return (
    <header className="site-header">
      <NavLink className="brand" to="/" aria-label="Frame home">
        <span className="brand-mark">F</span>
        <span>frame</span>
      </NavLink>
      <nav className="main-nav" aria-label="Main navigation">
        <NavLink to="/" end>
          Search
        </NavLink>
        <NavLink to="/collection">Collection</NavLink>
      </nav>
    </header>
  )
}

export default Navbar
