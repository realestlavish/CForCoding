#include <bits/stdc++.h>
using namespace std;

void cfLogo(int n) {
  int rem = n / 3;
  int first = 0, sec = 0, third = 0;
  if (n % 3 == 1) {
    first = rem + 2;
    sec = rem;
    third = rem - 1;
  } else if (n % 3 == 2) {
    first = rem + 2;
    sec = rem + 1;
    third = rem - 1;
  } else if (n % 3 == 0) {
    first = rem + 1;
    sec = rem;
    third = rem - 1;
  }
  cout << sec << " " << first << " " << third << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cfLogo(n);
  }
  return 0;
}