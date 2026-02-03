#include <bits/stdc++.h>
using namespace std;

int NestFinder(string s)
{
    int cnt = 0;
    int maxcnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (cnt < 0)
            cnt = 0;
        if (s[i] == '(')
            cnt++;
        maxcnt = max(cnt, maxcnt);
        if (s[i] == ')')
            cnt--;
        
    }
    return maxcnt;
}

int main()
{
    string str1 = "(1)+((((2))))+(((3)))";

    int ss = NestFinder(str1);
    cout<<ss;

    return 0;
}
