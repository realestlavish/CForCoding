#include <bits/stdc++.h>
using namespace std;

int peakelementb1(vector<int> arr, int n)
{
    int el = 0;
    if (n == 1)
        return arr[0];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[i] > arr[i + 1])
                el = i;
        }
        else if (i == n - 1)
        {
            if (arr[i] > arr[i - 1])
                el = i;
        }
        else if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
        {
            el = i;
        }
    }
    return el;
}

int peakelementbs(vector<int> arr, int n)
{
    if (n == 1)
        return arr[0];
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;
    int low = 1;
    int high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            return mid;
        }
        else if (arr[mid - 1] < arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int n = arr.size();
    int result = peakelementb1(arr, n);
    cout << "Peak element in the array is: " << result << endl;
    return 0;
}