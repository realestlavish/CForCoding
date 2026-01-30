#include <bits/stdc++.h>
using namespace std;

int onecounterinrow(vector<int> &row, int k)
{
    int m = row.size();
    int low = 0;
    int high = m - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (row[mid] == k)
            return 1;
        else if (row[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

int binary1(vector<vector<int>> &arr, int k)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (onecounterinrow(arr[i], k)) return 1;
    }
    return 0;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    int target = 4;
    bool result_binary = binary1(mat, target);
    cout << "binary1 found: " << (result_binary ? "true" : "false") << endl;

    return 0;
}