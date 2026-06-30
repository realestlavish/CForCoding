#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void goodcarpet(int n, int m) {
  vector<string> carpet(n);
  for (int row = 0; row < n; row++) {
    cin >> carpet[row];
  }
  string vika = "vika";
  int vint = 0;
  for (int col = 0; col < m; col++) {
    bool finder = false;
    for (int row = 0; row < n; row++) {
      if (carpet[row][col] == vika[vint]) {
        finder = true;
      }
    }
    if (finder) {
      vint++;

      if (vint == 4) {
        break;
      }
    }
  }
  if (vint == 4) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    goodcarpet(n, m);
  }

  return 0;
}