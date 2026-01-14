#include <bits/stdc++.h>
using namespace std;

void alternatearr(vector<int> &arr, int n)
{
    vector<int> s1;
    vector<int> s2;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            s1.push_back(arr[i]);
        }
        else
        {
            s2.push_back(arr[i]);
        }
    }
    sort(s1.begin(), s1.end());
    int p = 0, q = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            arr[i] = s1[p++];
        else
            arr[i] = s2[q++];
    }
}

void alternatearroptimal(vector<int> &arr, int n)
{
    int pos = 0;
    int neg = 1;
    vector<int> temp(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            temp[pos] = arr[i];
            pos += 2;
        }
        else
        {
            temp[neg] = arr[i];
            neg += 2;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
}
int main()
{
    vector<int> arr = {1, 2, -3, -1, -2, 3};
    int n = arr.size();
    alternatearroptimal(arr, n);

    return 0;
}