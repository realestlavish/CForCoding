#include "math.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void swapper(int n, int k) {
  vector<int> a(n);
  bool swap = true;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 0 && a[i] < a[i - 1]) {
      swap = false;
    }
  }
  if (k > 1 || swap) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    swapper(n, k);
  }

  return 0;
}