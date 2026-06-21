#include <cmath>
#include <iostream>


using namespace std;

void router(int a, int b) {
  int diff = abs(a - b);
  int steps = diff / 10;
  if (diff % 10 != 0) {
    steps++;
  }

  cout << steps << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    router(a, b);
  }

  return 0;
}