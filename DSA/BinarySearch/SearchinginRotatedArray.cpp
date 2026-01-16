#include <bits/stdc++.h>
using namespace std;

int Rotater(vector<int> arr, int n, int target)
{
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int ElRotater(vector<int> arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            break;
        }
        else if (arr[low] <= arr[mid])
        {
            if (arr[low] <= target && target <= arr[mid])
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        else if (arr[mid] <= arr[high])
        {
            if (arr[mid] <= target && target <= arr[high])
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {6, 7, 8, 9, 0, 1, 2, 3, 4, 5};
    int n = arr.size();
    int target = 9;
    int result = ElRotater(arr, n, target);
    cout << "Occurence of " << target << " is at index: " << result << endl;
    return 0;
}