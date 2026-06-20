#include <iostream>

using namespace std;

void bacteriabytwo(int n) {
  int count = 0;
  while (n > 0) {
    if (n % 2 != 0) {
      count++;
    }
    n /= 2;
  }
  cout << count << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  if (cin >> n) {
    bacteriabytwo(n);
  }
  return 0;
}