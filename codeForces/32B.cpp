#include <bits/stdc++.h>
using namespace std;

void translator(string s) {
  string message = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '.') {
      message += '0';
    } else if (s[i] == '-') {
      if (s[i + 1] == '.') {
        message += '1';
      } else if (s[i + 1] == '-') {
        message += '2';
      }
      i++;
    }
  }
  cout << message << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  translator(s);

  return 0;
}