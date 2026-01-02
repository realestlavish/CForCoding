#include <bits/stdc++.h>
using namespace std;

/*void majorityelementbrute(vector<int> &arr, int k)
{
    for (int i = 0; i < k; i++)
    {
        int temp = arr[i];
        int cnt = 0;
        for (int j = 0; j < k; j++)
        {
            if (arr[j] == temp)
            {
                cnt++;
            }
        }

        if (cnt > k / 2)
        {
            cout << temp << " ";
        }
    }
}

void majorityelementbetter(vector<int> &arr, int k)
{
    map<int, int> mpp;
    for (int i = 0; i < k; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second > k / 2)
        {
            cout << it.first << " ";
        }
    }
}*/

void majorityelementoptimal(vector<int> &arr, int k)
{
    int low = 0;
    int cnt = 0;
    int cnt1 = 0;
    int temp = arr[low];
    for (int i = 0; i < k; i++)
    {
        if (arr[i] == temp)
        {
            cnt++;
        }
        else if (arr[i] != temp)
        {
            cnt--;
        }
        else if (cnt == 0)
        {
            low = i;
            cnt = 1;
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (arr[i] == temp)
        {
            cnt1++;
        }
    }
    if (cnt1 > k / 2)
    {
        cout << temp << " ";
    }
}

int main()
{
    vector<int> arr = {7, 0, 0, 1, 7, 7, 2, 7, 7};
    int n = arr.size();
    majorityelementoptimal(arr, n);

    return 0;
}