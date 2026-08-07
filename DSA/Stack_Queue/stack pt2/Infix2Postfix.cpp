#include <iostream>
#include <stack>
#include <string>
using namespace std;

int ret_value(char c)
{
    if (c == '^')
        return 2;
    if (c == '+' || c == '-')
        return 0;
    if (c == '*' || c == '/')
        return 1;
    return -1;
}

string Infix2Postfix(string s)
{
    stack<char> st;
    string res = "";
    for (int it = 0; it < s.length(); it++)
    {
        char c = s[it];
        if (c == ' ')
        {
            continue;
        }
        else if (isalnum(c))
        {
            res += c;
        }
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && ret_value(c) <= ret_value(st.top()))
            {
                res += st.top();
                st.pop();
            }
            st.push(c); 
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}