#include <bits/stdc++.h>
using namespace std;

//T-C= log(1e9)-for largest and lowest test case +(nlogm)-for counter and upperbound.

int Upperbound(vector<int> arr, int m, int target)
{
    int low = 0;
    int high = m - 1;
    int ans = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int smallthanmidinrowcounter(vector<vector<int>> arr, int n, int m, int target)
{
    int cnt = -1;
    for (int i = 0; i < n; i++)
    {
        cnt += Upperbound(arr[i], m, target);
    }
    return cnt;
}

int binarymedianfinder(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int low = -1, high = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            low = min(low, arr[i][j]);
            high = max(high, arr[i][j]);
        }
    }
    int required = (n * m) / 2;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallthanmidinrow = smallthanmidinrowcounter(arr, n, m, mid);
        if (smallthanmidinrow <= required)
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
    vector<vector<int>> mat = {
        {1, 4, 9}, {2, 5, 6}, {3, 7, 8}};
        int median = binarymedianfinder(mat);
        cout << "\nMedian of 2D Matrix: " << median << endl;

    return 0;
}