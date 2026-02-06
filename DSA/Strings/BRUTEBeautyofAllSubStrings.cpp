#include <bits/stdc++.h>
using namespace std;

int beautysum(string subst){
    unordered_map<char,int> substmapper;
    int maxi=0;
    int mini=INT_MAX;
    for (int i = 0; i < subst.length(); i++)
    {
        substmapper[subst[i]]++;
    }
    for(auto it :substmapper){
        maxi=max(maxi,it.second);
        mini=min(mini,it.second);
    }
    return maxi-mini;
}
int beautyfinder(string s)
{
    int beautycnt = 0;
    for (int left = 0; left < s.length(); left++)
    {
        string temp;
        for (int right = left; right < s.length(); right++)
        {
            temp = s.substr(left, right-left+1);
            if(temp.length()>1){
                beautycnt+=beautysum(temp);
            }
        }
    }
    cout << endl;
    return beautycnt;
}

int main()
{
    string str1 = "xyx";

    int ss = beautyfinder(str1);
    cout << ss;

    return 0;
}
