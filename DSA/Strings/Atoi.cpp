#include <bits/stdc++.h>
using namespace std;

bool integerchecker(char s)
{
    if (isdigit(s))
        return true;
    else
        return false;
}

int AtoiConverter(string s)
{
    int converted = 0;
    int sign=1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ') continue;
        if (s[i]=='-'||s[i]=='+'){
            if(s[i]=='-') sign =-1;
            continue;
        }
        if (!integerchecker(s[i])) break;
        else
        {
            converted = converted * 10;
            converted += (s[i]-'0');
        }
    }
    return converted*sign;
}

int main()
{
    string str1 = "-982";

    int ss = AtoiConverter(str1);
    cout << ss;

    return 0;
}
