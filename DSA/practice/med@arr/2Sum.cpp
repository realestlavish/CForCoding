#include <bits/stdc++.h>
#include <set>
using namespace std;

set<pair<int, int>> TwoSumBrute(const vector<int> &arr, int k)
{
    int sum = 0;
    set<pair<int, int>> s;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size() - 1; j++)
        {
            sum = arr[i] + arr[j];
            if (sum == k)
            {
                s.insert({arr[i], arr[j]});
            }
        }
        if (s.begin() == s.end())
        {
            s.insert({-1, -1});
        }
    }
    return s;
}

set<pair<int, int>> TwoSumBetter(const vector<int> &arr, int k)
{
    int sum = 0;
    set<pair<int, int>> s;
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        int a = arr[i];
        int rem = k - a;
        if (mpp.find(rem) != mpp.end())
        {
            s.insert({min(a, rem), max(a, rem)});
        }
        mpp[a] = i;
    }
    if (s.begin() == s.end())
    {
        s.insert({-1, -1});
    }
    return s;
}

set<pair<int, int>> TwoSumOptimal(const vector<int> &arr, int k)
{
    vector<int> temp = arr; // since arr is const, make a copy to sort
    sort(temp.begin(), temp.end());
    int low = 0;
    int high = temp.size() - 1;
    int sum = 0;
    set<pair<int, int>> s;
    while (low < high)
    {
        sum = temp[low] + temp[high];
        if (sum == k)
        {
            s.insert({temp[low], temp[high]});

            int left = temp[low];
            int right = temp[high];

            // skip duplicates
            while (low < high && temp[low] == left)
                low++;
            while (low < high && temp[high] == right)
                high--;
        }

        else if (sum > k)
        {
            high--;
        }
        else if (sum < k)
        {
            low++;
        }
    }
    if (s.empty())
    {
        s.insert({-1, -1});
    }
    return s;
}

int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    int n = arr.size();
    int k = 15;
    int result = 0;
    set<pair<int, int>> res = TwoSumBrute(arr, k);
    for (auto p : res)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
