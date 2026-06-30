#include <bits/stdc++.h>
using namespace std;

void shovel(int n, int x) {

  for (int i = 1; i <= 9; i++) {
    if ((n * i) % 10 == 0 || (n * i) % 10 == x) {
      cout << i;
      break;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  shovel(n, x);

  return 0;
}