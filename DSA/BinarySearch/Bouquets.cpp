#include <bits/stdc++.h>
using namespace std;

int bouquetcounter(vector<int> &arr, int n, int i, int flowersPerBouquet)
{
    int countBouquets = 0;
    int numBouquets = 0;
    for (int j = 0; j < n; j++)
    {
        if (i >= arr[j])
        {
            countBouquets++;
        }
        else
        {
            numBouquets = numBouquets + (countBouquets / flowersPerBouquet);
            countBouquets = 0;
        }
    }
    numBouquets = numBouquets + (countBouquets / flowersPerBouquet);
    return numBouquets;
}
int bouquetbasic(vector<int> &arr, int n, int bouquets, int flowersPerBouquet)
{
    if (bouquets * flowersPerBouquet > n)
        return -1;
    int h = *max_element(arr.begin(), arr.end());
    int l = *min_element(arr.begin(), arr.end());
    for (int i = l; i <= h; i++)
    {
        if (bouquetcounter(arr, n, i, flowersPerBouquet) == bouquets)
            return i;
    }
    return -1;
}
//
int binarybouquet(vector<int> &arr, int n, int bouquets, int flowersPerBouquet)
{
    if (bouquets * flowersPerBouquet > n)
        return -1;
    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());
    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (bouquetcounter(arr, n, mid, flowersPerBouquet) == bouquets)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int N = 8;
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int bouquets = 2;
    int flowersPerBouquet = 3;
    int result = binarybouquet(arr, N, bouquets, flowersPerBouquet);
    if (result == -1)
    {
        cout << "No solution found" << endl;
    }
    else
    {
        cout << "Minimum eating speed: " << result << endl;
    }
    return 0;
}