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

void optimalmajority3(vector<int> rest)
{
    int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;
    vector<int> vec;
    int n = rest.size();
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && el1 != rest[i])
        {
            cnt1 = 1;
            el1 = rest[i];
        }
        else if (cnt2 == 0 && el2 != rest[i])
        {
            cnt2 = 1;
            el2 = rest[i];
        }
        else if (rest[i] == el1)
        {
            cnt1++;
        }
        else if (rest[i] == el2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (rest[i] == el1)
        {
            cnt1++;
        }
        else if (rest[i] == el2)
        {
            cnt2++;
        }
    }
    int cond = int(n / 3);
    if (cnt1 > cond)
    {
        vec.push_back(el1);
    }
    if (cnt2 > cond)
    {
        vec.push_back(el2);
    }

    for (auto it : vec)
    {
        cout << it << " ";
    }
}

int main()
{
    vector<int> rest = {1, 2, 1, 1, 3, 2, 2, 2};
    optimalmajority3(rest);
    return 0;
}