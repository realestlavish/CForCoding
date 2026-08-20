#include<iostream>
#include<stack>
#include<string>
using namespace std;

string minByRemove(string sr,int k){
    stack<char> st;
    int n= sr.size();
    for (int i = 0; i < n; i++)
    {
        char digi=sr[i];
        while (!st.empty()&&k>0&& st.top()>digi)
        {
            st.pop(); 
            k--;
        }
        st.push(digi);
    }
    while (k>0&&!st.empty())
    {
        st.pop();
        k--;
    }
    if(st.empty()) return "0";
    
    string res ="";
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    while (res.size()>0 && res.back()=='0')
    {
        res.pop_back();
    }
    reverse(res.begin(),res.end());
    if (!res.empty()) {
    return res;
    } else return "0";
} 