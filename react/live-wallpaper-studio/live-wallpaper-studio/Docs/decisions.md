# Decisions and tradeoffs

This document records the meaningful choices reflected in the current
implementation.

## React single-page app with Vite

**Decision:** Use Vite to serve and bundle the React app, with React Router for
client-side navigation.

**Tradeoff:** The app requires the Vite development/build workflow rather than
a static-only server such as VS Code Live Server. In return, JSX, module
imports, environment variables, and client-side routes work as expected.

## Direct provider API requests

**Decision:** The browser calls Unsplash and Giphy directly through Axios.

**Tradeoff:** This keeps the app and deployment architecture simple and avoids
adding a server solely to proxy requests. Vite `VITE_*` variables are bundled
into client code and must not be treated as secret credentials. A production
deployment that needs protected keys, provider-specific rate limiting, or
centralized API policy should move provider calls behind a backend.

## Unsplash for photos and Giphy for GIFs

**Decision:** The supported search categories are Photos (Unsplash) and GIFs
(Giphy). The previous Pexels video and Tenor integrations are not part of the
current feature set.

**Tradeoff:** Fewer providers simplify API-key setup, response normalization,
and the interface. Video search is not available.

## Redux Toolkit for shared app state

**Decision:** Keep search state and collection state in separate Redux Toolkit
slices, accessed by components through React Redux hooks.

**Tradeoff:** This introduces Redux dependencies and some action/reducer
boilerplate compared with local component state. It allows the search controls,
results, navigation pages, and collection cards to share consistent state.

## Common media shape at the result boundary

**Decision:** Normalize Unsplash and Giphy responses in `ResultGrid` before
putting them in Redux.

**Tradeoff:** Each provider's response format needs a mapping, but cards and
collection code can work with one predictable set of fields instead of being
coupled to provider response details.

## LocalStorage persistence via store middleware

**Decision:** Initialize the collection from localStorage and persist
collection actions in Redux middleware.

**Tradeoff:** Saved items survive reloads in the same browser, but are local to
that browser and are not synchronized between devices or users. Storage is
unavailable to other browsers and can be cleared by the user. The slice logs
and falls back to an empty collection if stored JSON cannot be parsed.

## Effect-driven searches and request cleanup

**Decision:** `ResultGrid` starts a request when the submitted query or active
tab changes and ignores responses from effects that have been cleaned up.

**Tradeoff:** This prevents stale responses from replacing results for a newer
selection, but it does not cancel the underlying HTTP request. Search results
are not cached, and page/limit parameters in the API helpers are not exposed
as pagination controls in the current interface.

## Error and empty states

**Decision:** Keep loading, error, and result-empty feedback visible in the
search page rather than silently substituting sample data.

**Tradeoff:** A provider error (including a missing key, rejected key, quota
limit, or network issue) means the user sees an error instead of fallback
content. The current interface reports the request error and suggests checking
the provider key; it does not implement retries or detailed provider-specific
error translation.
