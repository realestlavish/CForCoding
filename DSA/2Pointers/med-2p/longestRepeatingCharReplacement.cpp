#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int characterReplacement(string s, int k)
{
    int n = s.length();
    int maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> mp;
        for (int j = i; j < n; j++)
        {
            mp[s[j]]++;
            int substringLen = j - i + 1;
            int flipcnt = substringLen - mp[s[j]]; //Less frequent character count in the current substring (it needs to be flipped to make all characters same)
            if (flipcnt <= k)
            {
                maxlen = max(maxlen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    return maxlen;
}


int characterReplacementoptimal(string s, int k)
{
    int n = s.length();
    unordered_map<char, int> mp;
    int maxFreq = 0;
    int l = 0, r = 0, maxlen = 0, flipCnt = 0;
    while (r < n)
    {
        mp[s[r]]++;
        maxFreq = max(maxFreq, mp[s[r]]);
        int substrLen = r - l + 1;
        int needToFlip = substrLen - maxFreq;
        while (needToFlip > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
            {
                mp.erase(s[l]);
            }
            l++;
            // Recalculate needToFlip for the new window size
            substrLen = r - l + 1;
            needToFlip = substrLen - maxFreq;
        }
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}