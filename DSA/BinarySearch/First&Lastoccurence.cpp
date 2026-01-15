#include <bits/stdc++.h>
using namespace std;

int FirstLastoccurence(vector<int> arr, int n, int target)
{
    int first = -1;
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            if (first == -1)
            {
                first = i;
            }

            last = i;
        }
    }
    return last;
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

pair<int, int> FirstAndLastoccurenceBS(vector<int> arr, int n, int target)
{
    int first = FirstoccurenceBS(arr, n, target);
    if (first == -1)
    {
        return {-1, -1};
    }
    int last = LastoccurenceBS(arr, n, target);
    return {first, last};
}
int main()
{
    vector<int> arr = {6, 7, 8, 9, 10, 12, 13, 13, 13, 13, 16};
    int n = arr.size();
    int target = 60;
    pair<int, int> result = FirstAndLastoccurenceBS(arr, n, target);
    cout << " First and Last Occurence of " << target << " is at index: " << result.first << " and " << result.second << endl;
    return 0;
}