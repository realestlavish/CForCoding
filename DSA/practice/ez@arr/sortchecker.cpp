#include <bits/stdc++.h>
using namespace std;

void sortchecker(vector<int> arr)
{
    int n = arr.size() - 1;
    int i = 0;
    int ascending = 0;
    while (i < n)
    {
        if (arr[i] > arr[i + 1])
        {
            ascending = 1;
            break;
        }
        i++;
    }
    if (ascending == 1)
    {
        cout << "The array is not sorted" << endl;
    }
    else
    {
        cout << "The array is sorted in ascending order" << endl;
    }
}

int main()
{
    vector<int> arr = {1, 14, 8, 8, 9, 10};
    sortchecker(arr);
    return 0;
}