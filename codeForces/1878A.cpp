#include <iostream>
using namespace std;

void daytona(int n, int k) {
  int car = 0;
  bool found = false;
  for (int i = 0; i < n; i++) {
    cin >> car;
    if (car == k) {
      found = true;
    }
  }
  if (found) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  while (cin >> t) {
    while (t--) {
      int n, k;
      cin >> n >> k;

      daytona(n, k);
    }
  }

  return 0;
}