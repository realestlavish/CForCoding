#include <bits/stdc++.h>
using namespace std;

int sumfinder(vector<int> &vec, int sumlimit)
{
    int tempsum = 0;
    int parts = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (tempsum + vec[i] > sumlimit)
        {
            tempsum = vec[i];
            parts++;
        }
        tempsum += vec[i];
    }
    return parts;
}
int basicsplitarraylargesum(vector<int> arr, int n, int k)
{
    int max = *max_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);
    for (int i = max; i <= sum; i++)
    {
        if (sumfinder(arr, i) == k)
        {
            return i;
        }
    }
    return 0;
}

int splitarraylargesum(vector<int> arr, int n, int k)
{

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (sumfinder(arr, mid) <= k)
        {
            high = mid - 1;
        }
        else low = mid + 1;
    }

    return low;
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 3, 4, 5};
    int k = 3;
   // cout << "Result from basicsplitarraylargesum: " << basicsplitarraylargesum(a, N, k) << endl;
    cout << "Result from splitarraylargesum: " << splitarraylargesum(a, N, k) << endl;
    return 0;
}