# Application flow

## Overview

Frame is a Vite-powered React single-page app for searching Unsplash photos and
Giphy GIFs, then saving selected media in a browser-local collection. There is
no application backend: the browser calls the provider APIs directly.

## Startup and routing

1. Vite loads `index.html`, which mounts the app through `src/main.jsx`.
2. `main.jsx` renders the app inside React `StrictMode`, Redux `Provider`, and
   React Router's `BrowserRouter`.
3. The Redux store is created in `src/redux/store.js`. Its reducers provide
   `search` and `collection` state.
4. `src/App.jsx` renders the shared navigation and selects a page:
   - `/` renders `HomePage`.
   - `/collection` renders `CollectionPage`.
   - Unknown paths redirect to `/`.

## Search flow

1. `SearchBar` reads `search.query` and dispatches `setQuery` as the user types.
   Submitting the form dispatches `submitSearch`, which trims the text and saves
   it as `search.submittedQuery`.
2. `Tabs` dispatches `setActiveTab` to switch between Photos and GIFs.
3. `HomePage` displays the current submitted query and selected media type.
4. `ResultGrid` observes `submittedQuery` and `activeTab` with a React effect.
   An empty query clears results and status; otherwise it sets loading and
   clears any prior error before requesting data.
5. `src/api/mediaApi.js` calls Unsplash photo search or Giphy GIF search using
   Axios. The key is read from the Vite environment variables
   `VITE_UNSPLASH_KEY` and `VITE_GIPHY_KEY`; a missing key raises an error.
6. `ResultGrid` converts provider responses to a common media shape
   (`id`, `type`, `url`, `thumbnail`, `title`, `source`, and `pageUrl`).
   Successful responses update `search.results`; failures clear results and
   update `search.error`. Loading is cleared when the request settles.
7. The effect marks its request as cancelled during cleanup so a response from
   an obsolete query or tab does not update the Redux store.
8. `ResultGrid` renders the empty, loading, error, or result state. Each result
   is displayed by `ResultCard`, which links to the provider's media page.

## Collection flow

1. A result card checks `collection` for the media item's normalized ID.
   Selecting Save dispatches `saveMedia`; duplicate IDs are ignored by the
   collection reducer.
2. The collection reducer's initial state is loaded from the
   `wallpaper-studio-collection` localStorage entry.
3. The `collectionPersistence` middleware in `src/redux/store.js` persists
   collection state after `saveMedia` and `removeMedia`; `clearCollection`
   removes the storage entry.
4. `CollectionPage` reads the Redux collection and renders either its saved
   items or an empty state. `CollectionCard` provides item removal, and the
   page provides a clear-all action when there are saved items.

## Source map

- `src/main.jsx`: React root and global providers.
- `src/App.jsx`: shared shell and route definitions.
- `src/pages/HomePage.jsx`: search page composition and result heading.
- `src/pages/CollectionPage.jsx`: saved items and collection actions.
- `src/components/Navbar.jsx`: links between the two routes.
- `src/components/SearchBar.jsx`: controlled search input and submit action.
- `src/components/Tabs.jsx`: Photos/GIFs selection.
- `src/components/ResultGrid.jsx`: provider request lifecycle, response
  normalization, and result/feedback rendering.
- `src/components/ResultCard.jsx`: search result presentation and save action.
- `src/components/CollectionCard.jsx`: saved item presentation and removal.
- `src/api/mediaApi.js`: Axios wrappers for Unsplash and Giphy.
- `src/redux/store.js`: Redux store and collection persistence middleware.
- `src/redux/features/searchSlice.js`: query, tab, result, loading, and error
  state.
- `src/redux/features/collectionSlice.js`: saved items and storage key.
- `src/App.css`, `src/index.css`: app layout, responsive styling, and global
  styles.

## Running locally

From this app's directory, set `VITE_UNSPLASH_KEY` and `VITE_GIPHY_KEY` in a
`.env` file, then run `npm install` and `npm run dev`. Vite serves the app and
handles JSX/module loading; a static-only server is not sufficient.
