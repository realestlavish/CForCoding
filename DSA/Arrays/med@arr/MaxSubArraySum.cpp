#include <bits/stdc++.h>
using namespace std;

/*void maxsumarrbrute(vector<int> &arr, int k)
{
    int maxi = INT16_MIN;
    for (int i = 0; i < k; i++)
    {
        int sum = 0;
        for (int j = i; j < k; j++)
        {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    cout << maxi;
}*/

void maxsumarr(vector<int> &arr, int k)
{
    long long sum = 0;
    int maxi = INT_MIN; // Use INT_MIN for proper handling of all-negative arrays
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << maxi;
}

int main()
{
    vector<int> arr = {-2, -3, -7, -2, -10, -4};
    int n = arr.size();
    maxsumarr(arr, n);

    return 0;
}