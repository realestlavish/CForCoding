#include <bits/stdc++.h>
using namespace std;

vector<int> brutemajority3(vector<int> rest)
{
    vector<int> vec;
    int n = rest.size();
    for (int i = 0; i <= n - 1; i++)
    {
        int num = rest[i];
        int cnt = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (num == rest[j])
            {
                cnt++;
                if (cnt > (n / 3))
                {
                    vec.push_back(rest[i]);
                }
            }
        }
        if (vec.size() == 2)
        {
            break;
        }
    }
    for (auto it : vec)
    {
        cout << it << " ";
    }
    return vec;
}

vector<int> bettermajority3(vector<int> rest)
{
    vector<int> vec;
    int n = rest.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[rest[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second > (n / 3))
        {
            vec.push_back(it.first);
        }
    }
    for (auto it : vec)
    {
        cout << it << " ";
    }
    return vec;
}

int main()
{
    vector<int> rest = {1, 2, 1, 1, 3, 2, 2};
    bettermajority3(rest);
    return 0;
}