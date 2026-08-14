#include <vector>
#include <iostream>
using namespace std;

int rainTrapper(vector<int> arr)
{
    int n = arr.size();
    int l = 0, r = n - 1, lmax = 0, rmax = 0, total = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[l] <= arr[r])
        {
            if (lmax > arr[l])
            {
                total += lmax - arr[l];
            }
            else
                lmax = arr[l];
            l++;
        }
        else
        {
            if (rmax > arr[r])
            {
                total += rmax - arr[r];
            }
            else
                rmax = arr[r];
            r--;
        }
    }
    return total;
}

int main()
{
    vector<int> vec = {4, 2, 0, 3, 2, 5};
    int res = rainTrapper(vec);
    cout << res << endl;
}