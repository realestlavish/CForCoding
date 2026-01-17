#include <bits/stdc++.h>
using namespace std;

bool DoubleRotater(vector<int> arr, int n, int target)
{
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            ans = true;
            break;
        }
    }
    return ans;
}

bool ElRotater(vector<int> arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    bool ans = false;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            ans = true;
            break;
        }
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
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
    vector<int> arr = {3, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3};
    int n = arr.size();
    int target = 2;
    bool result = ElRotater(arr, n, target);
    cout << "Occurence of " << target << " is at index: " << result << endl;
    return 0;
}