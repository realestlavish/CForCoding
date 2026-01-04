#include <bits/stdc++.h>
using namespace std;

void Leader(vector<int> arr)
{
    int n = arr.size();
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                leader = false;
                break;
            }
        }
        if (leader == true)
        {
            s.insert(arr[i]);
        }
    }
    cout << "Leaders are: ";
    for (auto it : s)
    {
        cout << it << " ";
    }
}

void OptimalLeader(vector<int> arr)
{
    int n = arr.size();
    set<int> s;
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            maxi = max(maxi, arr[i]);
            s.insert(maxi);
        }
    }
    for (auto it : s)
    {
        cout << it << " ";
    }
}

int main()
{

    vector<int> arr = {10, 22, 12, 3, 0, 6};
    OptimalLeader(arr);

    return 0;
}