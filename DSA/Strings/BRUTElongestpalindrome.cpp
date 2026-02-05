#include <bits/stdc++.h>
using namespace std;
bool palindromechecker(string tr)
{
    int n = tr.length();
    for (int i = 0; i < tr.length() / 2; i++)
    {
        if (tr[i] != tr[n - i - 1])
            return false;
    }
    return true;
}
string longestpalindromkestring(string s)
{
    int n = s.length();
    int stringlenmax = -1;
    string tempstring;
    for (int left = 0; left < n; left++)
    {
        for (int right = left; right < n; right++)
        {
            string tr="";
            for (int k = left; k <= right; k++)
            {
                tr += s[k];
            }
            if (palindromechecker(tr))
            {
                if (tr.length() > stringlenmax)
                {
                    stringlenmax = tr.length();
                    tempstring = tr;
                }
            }
        }
    }
    return tempstring;
}

int main()
{
    string str1 = "cbbd";

    string ss = longestpalindromkestring(str1);
    cout << ss;

    return 0;
}
