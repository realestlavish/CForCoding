#include <bits/stdc++.h>
#include <set>
using namespace std;

int sumtokpositives(int arr[], int k, int n)
{
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int low = arr[i];
        int cnt = 1;

        for (int j = i + 1; j < n; j++)
        {
            int temp = low + arr[j];
            if (temp == k)
            {
                cnt++;
                maxi = max(maxi, cnt);
            }
            else if (temp < k)
            {
                cnt++;
                low = temp;
            }
            else
                return 0;
        }
    }
    return maxi;
}
int main()
{
    int arr[] = {-3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    int res = sumtokpositives(arr, k, n);
    cout << res;
    return 0;
}
