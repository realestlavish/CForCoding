#include <bits/stdc++.h>
using namespace std;

int rotationFinder(vector<int> arr)
{
    int ans = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            ans = i + 1;
            break;
        }
    }
    return ans;
}

int smallElRotater(vector<int> arr)
{
    int low = 0;
    int index = -1;
    int high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[mid] && arr[mid] <= arr[high])
        {
            ans = arr[low];
            break;
        }

        else if (arr[low] <= arr[mid])
        {

            ans = min(ans, arr[low]);
            index = low;
            low = mid + 1;
        }
        else
        {

            high = mid - 1;
            ans = min(ans, arr[mid]);
            index = mid;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {
        3,
        4,
        5,
        1, 2};
    int n = arr.size();
    int target = 2;
    int result = smallElRotater(arr);
    cout << result << endl;
    return 0;
}