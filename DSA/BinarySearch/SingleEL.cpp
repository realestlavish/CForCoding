#include <bits/stdc++.h>
using namespace std;

int singleelementb1(vector<int> arr, int n)
{
    int cnt = 0;
    int el = arr[0];
    if (n == 1)
        return arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
        {
            cnt++;
        }
        else
        {
            if (cnt == 1)
                return el;
            el = arr[i];
            cnt = 1;
        }
    }
    return -1;
}

int singlelementb2(vector<int> arr, int n)
{
    if (n == 1)
        return arr[0];

    int cnt = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return -1;
}

int singleelementbs(vector<int> arr, int n)
{
    if (n == 1)
        return arr[0];
    int low = 0;
    int high = n - 2;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[0]!=arr[1]) return arr[0];
        else if (arr[n - 1] != arr[n - 2]) return arr[n - 1];
        else if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            ans = arr[mid];
            break;
        }
        else if (arr[mid] == arr[mid + 1]) high=mid-1;
        else if (arr[mid] == arr[mid - 1]) low=mid+1;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1,1, 2, 2,3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 9, 9};
    int n = arr.size();
    int result = singleelementb1(arr, n);
    cout << "Single element in the array is: " << result << endl;
    return 0;
}