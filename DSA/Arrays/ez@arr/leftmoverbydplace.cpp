#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
void brutedleftmover(vector<int> arr, int d)
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

// Optimal Code
void optimaldleftmover(vector<int> arr, int d)
{
    int n = arr.size();
    d = d % n; // in case d is greater than n
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{
    int d = 2;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    brutedleftmover(arr, d);
    optimaldleftmover(arr, d);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}