#include <bits/stdc++.h>
using namespace std;

int countSubsequences(const vector<int> &arr, int index, int currentSum, int k)
{
    if (index == (int)arr.size())
    {
        return currentSum == k ? 1 : 0;
    }

    int include = countSubsequences(arr, index + 1, currentSum + arr[index], k);
    int exclude = countSubsequences(arr, index + 1, currentSum, k);
    return include + exclude;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int k = 2;
    int result = countSubsequences(arr, 0, 0, k);
    cout << "Count of subsequences with sum " << k << " = " << result << endl;
    return 0;
}
