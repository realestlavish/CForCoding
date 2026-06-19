#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>

using namespace std;
void targetPractice() {
  int point = 0;
  for (int row = 0; row < 10; row++) {
    string line;
    cin >> line;
    for (int col = 0; col < 10; col++) {
      if (line[col] == 'X') {
        int miniDistance = min({row, col, 9 - row, 9 - col});
        point += (miniDistance + 1);
      }
    }
  }
  cout << point << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  if (cin >> t) {
    while (t--) {
      targetPractice();
    }
  }

  return 0;
}