#include <bits/stdc++.h>
using namespace std;

void maxsumarr(vector<int> &arr, int k)
{
    long long sum = 0;
    int start;
    int Ansstart;
    int AnsEnd;
    int maxi = INT_MIN; // Use INT_MIN for proper handling of all-negative arrays
    for (int i = 0; i < k; i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
            Ansstart = start;
            AnsEnd = i;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << maxi << endl;
    for (int i = Ansstart; i <= AnsEnd; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = {2, 3, 5, -2, 7, -4};
    int n = arr.size();
    maxsumarr(arr, n);

    return 0;
}