#include <bits/stdc++.h>
using namespace std;

// Ceil is same as lower_bound function

int Floor(vector<int> arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= target)
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
    vector<int> arr = {2, 6, 9, 10, 15, 20, 25};
    int n = arr.size();
    int target = 12;
    cout << "Floor of " << target << " is at index: " << Floor(arr, n, target) << endl;
    return 0;
}