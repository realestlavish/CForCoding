#include <bits/stdc++.h>
using namespace std;

//Same as Lowerbound, Number >= target at lowest index.
int Insertpos(vector<int> arr, int n, int target)
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
    vector<int> arr = {
        2,
        6,
        9,
        10,
        12,
    };
    int n = arr.size();
    int target = 6;
    cout << "Insert Position of " << target << " is at index: " << Insertpos(arr, n, target) << endl;
    return 0;
}