#include <bits/stdc++.h>
using namespace std;

int beautyfinder(string s)
{
    int n = s.length();
    int beautycnt = 0;

    for (int left = 0; left < n; left++)
    {
        unordered_map<char, int> freq;

        for (int right = left; right < n; right++)
        {
            freq[s[right]]++;

            int maxi = 0, mini = INT_MAX;
            for (auto &it : freq)
            {
                maxi = max(maxi, it.second);
                mini = min(mini, it.second);
            }

            beautycnt += (maxi - mini);
        }
    }
    return beautycnt;
}
