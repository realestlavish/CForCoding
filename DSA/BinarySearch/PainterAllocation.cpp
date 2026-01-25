#include <bits/stdc++.h>
using namespace std;

int paintimefinder(vector<int> &vec, int time)
{
    int currenttime = 0;
    int painters = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (currenttime + vec[i] > time)
        {
            currenttime = vec[i];
            painters++;
        }
        else
            currenttime += vec[i];
    }
    return painters;
}
int basicpainterallocation(vector<int> arr, int n, int k)
{
    if (k > n)
        return -1;
    int max = *max_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);
    for (int i = max; i <= sum; i++)
    {
        if (paintimefinder(arr, i) == k)
        {
            return i;
        }
    }
    return 0;
}

int binarypainterallocation(vector<int> arr, int n, int k)
{

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (paintimefinder(arr, mid) <= k)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return low;
}

int main()
{
    int N = 4;
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    cout << "Result from painterallocation: " << basicpainterallocation(a, N, k) << endl;
    cout << "Result from binarypainterallocation: " << binarypainterallocation(a, N, k) << endl;
    return 0;
}