#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int LongestSubStringWithKMostDistinct(string s, int k)
{
    int l = 0, r = 0, cnt = 0, n = s.length(), maxlen = 0;
    unordered_map<char, int> hash;
    while (r < n)
    {
        hash[s[r]]++;
        {
            while (hash.size() >= k)
            {
                hash[s[l]]--;

                if (hash[s[l]] == 0)
                {
                    hash.erase(s[l]);
                }

                l++;
            }
        }
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}