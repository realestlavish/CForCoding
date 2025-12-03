#include <bits/stdc++.h>
using namespace std;

// bubble sort compares the adjacent elements and swaps them if they are in the wrong order. starts from the n-1th index and goes to 1st index to exclude the already sorted elements at the end of the array.

void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        int didswap = 0;
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didswap = 1;
            }
        }
        if (didswap == 0)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}