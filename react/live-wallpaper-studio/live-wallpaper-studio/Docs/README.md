# Frame

Frame is a searchable gallery for Unsplash photos and Giphy GIFs. Save media to
your local collection and revisit or remove it later.

## Setup

Create a `.env` file in this directory with your provider API keys:

```env
VITE_UNSPLASH_KEY=your_unsplash_access_key
VITE_GIPHY_KEY=your_giphy_api_key
```

Then install dependencies and start the Vite development server:

```sh
npm install
npm run dev
```

The app uses the Unsplash photo search API and Giphy GIF search API. The
collection is stored in the browser's local storage.
