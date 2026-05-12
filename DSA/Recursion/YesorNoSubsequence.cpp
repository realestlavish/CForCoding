#include <bits/stdc++.h>
using namespace std;

bool checkSubsequences(const vector<int> &arr, int index, int currentSum, int k)
{
    if (index == (int)arr.size())
    {
        return currentSum == k ? true : false;
    }

    if (checkSubsequences(arr, index + 1, currentSum + arr[index], k) == true)
        return true;
    if (checkSubsequences(arr, index + 1, currentSum, k) == true)
        return true;
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int k = 2;
    bool result = checkSubsequences(arr, 0, 0, k);
    if (result)
    {
        cout << "subsequences with sum avaliable " << endl;
    }
    else
        cout << " subsequences with sum not avaliable " << endl;
    return 0;
}
