#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void pointer(int n, string s) {
  int count = 0;
  unordered_set<char> filter;

  for (int i = 0; i < s.length(); i++) {
    if (filter.find(s[i]) == filter.end()) {
      count += 2;
      filter.insert(s[i]);
    } else {
      count += 1;
    }
  }
  cout << count << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    pointer(n, s);
  }

  return 0;
}