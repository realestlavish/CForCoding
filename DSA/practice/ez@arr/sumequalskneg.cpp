#include <bits/stdc++.h>
#include <set>
using namespace std;

int sumtokbetter(int arr[], int k, int n)
{
    map<long long, int> presummp;
    int maxLen = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - k;
        if (presummp.find(rem) != presummp.end())
        {
            int len = i - presummp[rem];
            maxLen = max(maxLen, len);
        }
        presummp[sum] = i;
    }
    return maxLen;
}

int sumtokoptimal(int arr[], int k, int n)
{
    int maxLen = 0;
    int sum = 0;
    int low = 0;
    int high = 0;
    while (high <= n)
    {
        high++;
        if (high < n)
        {
            sum += arr[high];
        }
        if (sum > k && low <= high)
        {
            sum -= arr[low];
            low++;
        }
        if (sum == k && low <= high)
        {
            maxLen = max(maxLen, high - low + 1);
        }
    }
    return maxLen;
}
int main()
{
    int arr[] = {-3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    int res = sumtokbetter(arr, k, n);
    int res2 = sumtokoptimal(arr, k, n);
    cout << res;
    return 0;
}
