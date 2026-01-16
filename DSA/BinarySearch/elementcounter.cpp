#include <bits/stdc++.h>
using namespace std;

int Elcounter(vector<int> arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = 0;
    for (int i = low; i <= high; i++)
    {
        if (arr[i] == target)
        {
            ans++;
        }
    }

    return ans;
}

int FirstoccurenceBS(vector<int> arr, int n, int target)
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
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int LastoccurenceBS(vector<int> arr, int n, int target)
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
            low = mid + 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int ElCounterBS(vector<int> arr, int n, int target)
{
    int first = FirstoccurenceBS(arr, n, target);
    if (first == -1)
    {
        return -1;
    }
    int last = LastoccurenceBS(arr, n, target);
    int occurences = last - first + 1;
    return occurences;
}
int main()
{
    vector<int> arr = {2, 4, 6, 7, 8, 13, 13, 13, 13, 16, 18};
    int n = arr.size();
    int target = 13;
    cout << "Element Count of " << target << " is: " << ElCounterBS(arr, n, target) << endl;
    return 0;
}