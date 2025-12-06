#include <bits/stdc++.h>
using namespace std;

void leftmover(vector<int> arr)
{
    int tmp = 0;
    tmp = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[arr.size() - 1] = tmp;
    for (auto it : arr)
    {
        cout << it << " ";
    }
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    leftmover(arr);

    return 0;
}