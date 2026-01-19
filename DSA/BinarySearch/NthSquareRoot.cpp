#include <bits/stdc++.h>
using namespace std;

int power(int base, int pow)
{
    int result = 1;
    for (int i = 0; i < pow; i++)
    {
        result *= base;
    }
    return result;
}

int Insertpos(int n, int m)
{
    int low = 1;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (power(mid, m) == n) {ans = mid; break;}
        else if (power(mid, m) <= n) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}
int main()
{
    int n = 27;
    int m = 3;
    cout << m << "th Square root of " << n << " is " << Insertpos(n, m) << endl;
    return 0;
}