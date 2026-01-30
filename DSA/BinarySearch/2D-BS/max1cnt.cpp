#include <bits/stdc++.h>
using namespace std;

int onecounterinrow(vector<int> &row)
{
    int m = row.size();
    int low=0;
    int high=m-1;
    int cnt = 0;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (row[mid]>=1)
        {
            cnt= m-mid;
            high=mid-1;
        }
        else low=mid+1;
        
    }
    return cnt;
}

int brute1(vector<vector<int>> &arr)
{
    int n = arr.size();
    int maxInd = -1;
    int max1 = 0;
    for (int i = 0; i <n; i++)
    {
        int count1 = onecounterinrow(arr[i]);
        if (count1 > max1)
        {
            max1 = count1;
            maxInd = i;
        }
    }
    return maxInd;
}


int binary1(vector<vector<int>> &arr)
{
    int n = arr.size();
    int maxInd = -1;
    int max1 = 0;
    for (int i = 0; i <n; i++)
    {
        int count1 = onecounterinrow(arr[i]);
        if (count1 > max1)
        {
            max1 = count1;
            maxInd = i;
        }
    }
    return maxInd;
}

int main()
{
    vector<vector<int>> arr = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 1}};

    int result = brute1(arr);
    int result1=binary1(arr);
    cout << "Row with maximum 1s: " << result << endl;
    cout << "Row with maximum 1s: " << result1 << endl;

    return 0;
}