#include <bits/stdc++.h>
using namespace std;

void potholes(int n, string s) {
  int count = 0;
  bool infinity =false;
  for (int i = 0; i < s.length(); i++) {
    if (i == 0) {
      if (s[i] == '.') {
        count++;
      } else
        count = 0;
    }
    if (i > 0 && s[i] == '.' && s[i - 1] == '.' && s[i + 1] == '.') {
      count=2;
      infinity=true;
    }
    if (i > 0 && s[i] == '.'&& infinity == false) {
      if (s[i - 1] == '#' || s[i + 1] == '#' || s[i + 1] == '.' ||
          s[i - 1] == '.') {
        count++;
      }
    } else if (s[i] == '#'&& infinity==false) {
      continue;
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
    potholes(n, s);
  }
  return 0;
}