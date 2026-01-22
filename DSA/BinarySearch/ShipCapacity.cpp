#include <bits/stdc++.h>
using namespace std;

int dayfounder(vector<int> &arr, int limit, int n)
{
    int load = 0;
    int daycount = 1;
    for (int j = 0; j < n; j++)
    {
        
        if (load + arr[j] > limit)
        {
            daycount++;
            load = arr[j];
        }
        else
            load += arr[j];
    }
    return daycount;
}
int shippingbasic(vector<int> &arr, int n, int daylimit)
{
    if (n == 1)
        return arr[0];
    int load = accumulate(arr.begin(), arr.end(), 0);
    int h = *max_element(arr.begin(), arr.end());
    for (int i = h; i <= load; i++)
    {
        if (dayfounder(arr, i, n) <= daylimit)
            return i;
    }

    return -1;
}

int binaryshipping(vector<int> &arr, int n, int daylimit)
{
    int low = *min_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (dayfounder(arr, mid, n) <= daylimit)
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
    int N = 8;
    vector<int> arr = {5, 4, 5, 2, 3, 4, 5, 6};
    int daylimit = 5;
    int result = binaryshipping(arr, N, daylimit);
    if (result == -1)
    {
        cout << "No solution found" << endl;
    }
    else
    {
        cout << "Minimum capacity: " << result << endl;
    }
    return 0;
}