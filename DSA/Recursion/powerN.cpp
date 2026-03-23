#include <bits/stdc++.h>
using namespace std;

double power(double x, int n){
    double ans=1.0;
    long long  pow=n;
    int check=0;
    if(pow<0) x=-1*x;
    while(pow>0){
        if (n%2==1)
        {
            ans=x*x;
            pow=pow-1;
        }
        else {
            x=x*x;
            pow=pow/2;
        }
    }
    if (n>0)ans= (double) 1.0/(double) ans;
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

    double ans = powerhelper(x, n);
    cout << ans << '\n';
    return 0;
}