#include <bits/stdc++.h>
using namespace std;

double power(double x, int n){
    double ans=1.0;
    long long pow = n;
    if(pow < 0){
        x = 1.0 / x;
        pow = -pow;
    }
    while(pow > 0){
        if(pow % 2 == 1){
            ans = ans * x;
        }
        x = x * x;
        pow = pow / 2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x;
    int n;
    if (!(cin >> x >> n))
        return 0;

    double ans = power(x, n);
    cout << ans << '\n';
    return 0;
}