#include <unordered_map>
#include <string>
using namespace std;
string minWindow(string s, string t)
{
    unordered_map<char, int> sMap;
    int minlen = INT_MAX, l = 0, r = 0;
    int m = t.length();
    int n = s.length();
    int resStart = -1, cnt = 0;
    for (int i = 0; i < t.length(); i++)
    {
        sMap[t[i]]++;
    }
    while (r < n)
    {
        if (sMap[s[r]] > 0)
        {
            cnt++;
        }
        sMap[s[r]]--;
        while (cnt == m)
        {
            if (r - l + 1 < minlen)
            {
                minlen = r - l + 1;
                resStart = l;
            }
            sMap[s[l]]++;
            if (sMap[s[l]] > 0)
            {
                cnt--;
            }
            l++;
        }
        r++;
    }
    return resStart == -1 ? "" : s.substr(resStart, minlen);
}