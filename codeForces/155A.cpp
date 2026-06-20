#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void love(int n) {
  int first_score;
  cin >> first_score;
  int maxSc = first_score;
  int minSc = first_score;
  int amazing = 0;
  for (int i = 0; i < n - 1; i++) {
    int curr_score;
    cin >> curr_score;
    if (curr_score > maxSc) {
      amazing++;
      maxSc = curr_score;
    }
    if (curr_score < minSc) {
      amazing++;
      minSc = curr_score;
    }
  }
  cout << amazing << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  while (cin >> n) {
    love(n);
  }

  return 0;
}