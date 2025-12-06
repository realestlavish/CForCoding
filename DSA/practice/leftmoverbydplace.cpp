#include <bits/stdc++.h>
using namespace std;

void dleftmover(vector<int> arr, int d)
{
    int n = arr.size();
    vector<int> temp;
    d = d % n; // in case d is greater than n
    //  tading out
    for (int i = 0; i < d; i++)
    {
        temp.push_back(arr[i]);
    }
    // placing remaining elements at the start
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    // placing temp elements at the end
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }

    for (auto it : arr)
    {
        cout << it << " ";
    }
}

int main()
{
    int d = 2;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    dleftmover(arr, d);

    return 0;
}