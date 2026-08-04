#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool balanced_para(string s)
{
    int n = s.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        int el = s[i];
        if (el == '(' | el == '{' | el == '[')
        {
            st.push(el);
        }
        else
        {
            if (st.empty())
                return false;
            char ch = st.top();
            st.pop();

            if ((el == ')' && ch == '(') ||
                (el == ']' && ch == '[') ||
                (el == '}' && ch == '{'))
                continue;
            else
                return false;
        }
    }
    return st.empty();
}

int main()
{
    string sp = "[(){{{{{{{}}}}}}}]";
    if (balanced_para(sp))
    {
        cout << "true"  << endl;
    }
    else
        cout << "false";
}