#include <bits/stdc++.h>
using namespace std;

void maxsumkbrute(vector<int> &arr, int n, int k)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}

void maxsumkoptimal(vector<int> &arr, int n, int k)
{
    int cnt = 0;
    int sum = 0;
    map<int, int> prefixSum;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            cnt++;
        }
        int rem = sum - k;
        if (prefixSum.find(rem) != prefixSum.end())
        {
            cnt += prefixSum[rem];
        }
        prefixSum[sum]++;
    }
    cout << cnt;
}

int main()
{
    vector<int> arr = {1, 2, 1, 2, 1};
    int n = arr.size();
    int k = 3;
    maxsumkoptimal(arr, n, k);

    return 0;
}