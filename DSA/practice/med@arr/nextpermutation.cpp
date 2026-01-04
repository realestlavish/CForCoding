#include <bits/stdc++.h>
using namespace std;

void nextpermutation(vector<int> arr)
{
    int n = arr.size();
    int index = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(arr.begin(), arr.end());
    }
    for (int i = n - 1; i < i + 1; i--)
    {
        if (arr[i] > arr[index])
        {
            swap(arr[i], arr[index]);
            break;
        }
    }
    sort(arr.begin() + index + 1, arr.end());
    for (auto it : arr)
    {
        cout << it << " ";
    }
}

int main()
{

    vector<int> arr = {1, 3, 5, 4, 2, 0, 0};
    nextpermutation(arr);

    return 0;
}