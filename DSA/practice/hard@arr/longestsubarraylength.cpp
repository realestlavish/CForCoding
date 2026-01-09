#include <bits/stdc++.h>
using namespace std;

int longestSubarrayLength(vector<int> &vec)
{
    int n = vec.size();
    int maxi = 0;
    unordered_map<int, int> mp;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += vec[i];

        if (sum == 0)
        {
            maxi = i + 1;
        }
        else if (mp.find(sum) != mp.end())
        {
            maxi = max(maxi, i - mp[sum]); // ✅ FIXED
        }
        else
        {
            mp[sum] = i;
        }
    }

    return maxi;
}

int main()
{
    vector<int> vec = {15, -2, 2, -8, 1, 7, 10, 23};

    int result = longestSubarrayLength(vec);
    cout << result << endl;

    return 0;
}
