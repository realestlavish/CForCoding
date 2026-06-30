#include <bits/stdc++.h>
using namespace std;

void xenia(string s) {
  int one = 0, two = 0, three = 0;
  string out = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '+')
      continue;
    else if (s[i] == '1')
      one++;
    else if (s[i] == '2')
      two++;
    else if (s[i] == '3')
      three++;
  }
  bool isFirst = true;

  for (int i = 0; i < one; i++) {
    if (!isFirst)
      out += "+";
    out += "1";
    isFirst = false;
  }
  for (int i = 0; i < two; i++) {
    if (!isFirst)
      out += "+";
    out += "2";
    isFirst = false;
  }
  for (int i = 0; i < three; i++) {
    if (!isFirst)
      out += "+";
    out += "3";
    isFirst = false;
  }
  cout << out;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;

  xenia(s);

  return 0;
}