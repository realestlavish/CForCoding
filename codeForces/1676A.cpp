#include <iostream>
#include <string>

using namespace std;

void solve() {
  string ticket;
  cin >> ticket;

  if (ticket.length() != 6) {
    cout << "NO\n";
    return;
  }

  int single = 0, backsum = 0, frontsum = 0;
  for (int i = 0; i < ticket.length(); i++) {
    single = ticket[i] - '0';
    if (i < 3) {
      frontsum += single;
    } else {
      backsum += single;
    }
  }

  if (frontsum == backsum) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  if (cin >> t) {
    while (t--) {
      solve();
    }
  }

  return 0;
}