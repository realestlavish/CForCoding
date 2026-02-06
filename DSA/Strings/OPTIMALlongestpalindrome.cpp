#include <bits/stdc++.h>
using namespace std;
int centerLENchecker(string tr,int left,int right)
{
    while (left>=0&&right<tr.length()&&tr[left]==tr[right])
    {
        left--; 
        right++;
    }
    return right-left-1;
}
string longestpalindromkestring(string s)
{
    int n = s.length();
    int lenODD = -1,lenEVEN=-1,maxLEN=-1;
    int end=0,start=0;
    for (int center = 0; center < n; center++)
    {
        lenODD=centerLENchecker(s,center,center);
        lenEVEN=centerLENchecker(s,center,center+1);
        maxLEN=max(lenEVEN,lenODD);
        if (maxLEN>end-start)
        {
            end=center+maxLEN/2;
            start=center-(maxLEN-1)/2;
        }
    }
    

    return s.substr(start, end - start + 1);;
}

int main()
{
    string str1 = "cbbd";

    string ss = longestpalindromkestring(str1);
    cout << ss;

    return 0;
}
