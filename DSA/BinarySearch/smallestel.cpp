#include <bits/stdc++.h>
using namespace std;

int smallestElement(vector<int> arr)
{
    int ans = -1;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, arr[i]);
    }
    return ans;
}
//we find the sorted part in the array and store its minimum and compare it with the minimmum found so far, and do the same with the unsorted part until we find the minimum element
int smallElRotater(vector<int> arr)
{
    int low = 0;
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
            low = mid + 1;
        }
        else
        {

            high = mid - 1;
            ans = min(ans, arr[mid]);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {
        3,
        4,
        5,
        6,
        7,
        0,
        1,
        2,
    };
    int n = arr.size();
    int target = 2;
    int result = smallElRotater(arr);
    cout << result << endl;
    return 0;
}