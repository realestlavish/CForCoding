#include <bits/stdc++.h>
using namespace std;

// also a way to swap without a temp variable within a vector or array
void dutchflagalgo(vector<int> &arr, int k)
{
    int low = 0;
    int mid = 0;
    int high = k - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main()
{
    vector<int> arr = {2, 1, 0, 2, 1, 0};
    int n = arr.size();
    dutchflagalgo(arr, n);

    return 0;
}