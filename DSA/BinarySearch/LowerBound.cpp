#include <bits/stdc++.h>
using namespace std;

int Lowerbound(vector<int> arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
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
int main()
{
    vector<int> arr = {2, 4, 5, 6, 9, 10, 12};
    int n = arr.size();
    int target = 3;
    cout << "Lower Bound of " << target << " is at index: " << Lowerbound(arr, n, target) << endl;
    return 0;
}