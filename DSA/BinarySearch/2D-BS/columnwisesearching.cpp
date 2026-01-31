#include <bits/stdc++.h>
using namespace std;

int finderinrow(vector<int> &row, int k)
{
    int m = row.size();
    int low = 0;
    int high = m - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (row[mid] == k)
            return mid;
        else if (row[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

pair<int, int> binarysortfinder(vector<vector<int>> &arr, int k)
{
    int n = arr.size();
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        index = finderinrow(arr[i], k);
        if (index != -1)
            return {i, index};
    }
    return {-1, -1};
}

pair<int, int> optimalsortfinder(vector<vector<int>> &arr, int k)
{
    int n = arr.size();
    int m = arr[0].size();
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (arr[i][j] == k)
            return {i, j};
        else if (arr[i][j] > k)
            j--;
        else
            i++;
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {
        {1, 4, 7, 11}, {2, 5, 8, 12}, {3, 6, 9, 16}, {10, 13, 14, 17}};

    int target = 14;
    pair<int, int> result = optimalsortfinder(mat, target);
    cout << "result found: {" << result.first << ", " << result.second << "}" << endl;

    return 0;
}