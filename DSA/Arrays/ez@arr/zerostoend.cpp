#include <bits/stdc++.h>
using namespace std;

int find1zero(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

void zerostoend(int arr[], int n)
{
    int j = find1zero(arr, n);
    if (j == -1)
    {
        return;
    }
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// Or

void zerostoendoptimalplus(int arr[], int n)
{
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[pos] = arr[i];
            pos++;
        }
    }
    for (int i = n - pos; i < n; i++)
    {
        arr[i] = 0;
    }
}

int main()
{

    int arr[] = {1, 0, 2, 3, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    zerostoend(arr, n);
    zerostoendoptimalplus(arr, n);
    return 0;
}