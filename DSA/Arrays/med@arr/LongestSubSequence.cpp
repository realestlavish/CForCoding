#include <bits/stdc++.h>
using namespace std;

// TC : o(n^3)
int LongestSubSequenceBrute(vector<int> arr)
{
    int n = arr.size();
    int Longest = 0;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int cnt = 1;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == x + 1)
            {
                cnt++;
                x++;
                j = 0;
            }
        }

        Longest = max(Longest, cnt);
    }
    cout << Longest;
    return 0;
}

int LongestSubSequenceBetter(vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int Longest = 1;
    int ls = INT_MIN;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] - 1 == ls)
        {
            ls = arr[i];
            cnt++;
        }
        else if (arr[i] != ls)
        {
            ls = arr[i];
            cnt = 1;
        }
        Longest = max(Longest, cnt);
    }

    cout << Longest;
    return 0;
}

int LongestSubSequenceOptimal(vector<int> arr)
{
    int longest = 1;
    unordered_set<int> s;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }
    for (auto it : s)
    {
        if (s.find(it - 1) == s.end())
        {
            cnt = 1;
            int x = it;
            while (s.find(x + 1) != s.end())
            {
                cnt++;
                x++;
            }
        }
        longest = max(longest, cnt);
    }

    cout << longest;
    return 0;
}

int main()
{
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    LongestSubSequenceOptimal(arr);
    return 0;
}