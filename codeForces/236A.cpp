#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
using namespace std;

void distincter(string s) {
  unordered_set<char> filter;
  int filtered_char = 0;

  for (auto it : s) {
    if (filter.find(it) == filter.end()) {
      filtered_char++;
      filter.insert(it);
    }
  }
  if (filtered_char % 2 == 0) {
    cout << "CHAT WITH HER!\n";
  } else {
    cout << "IGNORE HIM!\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  distincter(s);

  return 0;
}