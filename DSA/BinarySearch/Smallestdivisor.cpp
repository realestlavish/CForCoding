#include <bits/stdc++.h>
using namespace std;

int divfounder(vector<int> &arr, int divisor, int n)
{
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += ceil((double)arr[j] / divisor);
    }
    return sum;
}
int divisorbasic(vector<int> &arr, int n, int limit)
{
    if (n == 1)
        return arr[0];
    int l = *min_element(arr.begin(), arr.end());
    int h = *max_element(arr.begin(), arr.end());
    long long sum = 0;
    for (int i = l; i <= h; i++)
    {
        if (divfounder(arr, i, n) <= limit)
            return i;
    }

    return -1;
}

int binarydivisor(vector<int> &arr, int n, int limit)
{
    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());
    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long sum = 0;
        for (int j = 0; j < n; j++)
            if (divfounder(arr, mid, n) <= limit)
            {
                ans = mid;
                high = mid - 1;
            }
        low = mid + 1;
    }
    return ans;
}

int main()
{
    int N = 5;
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int result = divisorbasic(arr, N, limit);
    if (result == -1)
    {
        cout << "No solution found" << endl;
    }
    else
    {
        cout << "Minimum divisor: " << result << endl;
    }
    return 0;
}