#include <bits/stdc++.h>
#include <iostream>
#include <math.h>

using namespace std;
void arraybalancer(int n) {
  if (n % 4 != 0) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  int k = n / 2;
  long long frontsum = 0, backsum = 0;
  for (int i = 1; i <= k; i++) {
    int even_num = i * 2;
    cout << even_num << " ";
    frontsum += even_num;
  }
  for (int i = 1; i < k; i++) {
    int odd_num = (i * 2) - 1;
    cout << odd_num << " ";
    backsum += odd_num;
  }
  int last = frontsum - backsum;
  cout << last << "\n";
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  if (cin >> t) {
    while (t--) {
      int n;
      if (cin >> n) {
        arraybalancer(n);
      }
    }
  }

  return 0;
}