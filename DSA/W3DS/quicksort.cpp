#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[0];
    int i =low;
    int j= high;
        while (i < j)
    {
        while (arr[i] <= pivot && i<=high-1)
        {
            i++;
        }
        while (arr[j]> pivot && j>= low+1){
            j--;
        }
        if (i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j],arr[low]);
    return j;
}

int quicksort(vector<int>& arr, int low, int high)
{
    int pivot = 0;
    if (low < high)
    {
        pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    int res = 0;
    quicksort(arr, 0, n-1);
    cout << arr << endl;

    return 0;
}