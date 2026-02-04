#include <bits/stdc++.h>
using namespace std;

int RomanConverter(string s)
{
    int total=0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='I'&&s[i+1]=='V'||s[i]=='I'&&s[i+1]=='X') total-=1;
        else if(s[i]=='I'&&s[i+1]!='V'||s[i]=='I'&&s[i+1]!='X') total+=1;
        if(s[i]=='X'&&s[i+1]=='L'||s[i]=='X'&&s[i+1]=='C') total-=10;
        else if(s[i]=='X'&&s[i+1]!='L'||s[i]=='X'&&s[i+1]!='C') total+=10;
        if(s[i]=='C'&&s[i+1]=='M'||s[i]=='C'&&s[i+1]=='D') total-=100;
        else if(s[i]=='C'&&s[i+1]!='M'||s[i]=='C'&&s[i+1]!='D') total+=100;
        if(s[i]=='V') total+=5;
        if(s[i]=='L') total+=50;
        if(s[i]=='D') total+=500;
        if(s[i]=='M') total+=1000;
    }
    return total;
}

int main()
{
    string str1 = "CXIX";

    int ss = RomanConverter(str1);
    cout<<ss;

    return 0;
}
