#include <bits/stdc++.h>
using namespace std;

// Same as Lowerbound, Number >= target at lowest index.
int Insertpos(int n)
{
    int low = 1;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid * mid <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n = 28;
    cout << "Square root of " << n << " is " << Insertpos(n) << endl;
    return 0;
}