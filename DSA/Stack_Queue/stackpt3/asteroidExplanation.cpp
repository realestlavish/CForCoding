#include <vector>
#include <iostream>
#include <stack>
using namespace std;

stack<int> asteroid(vector<int> vec)
{
    stack<int> st;
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        if (vec[i] > 0)
            st.push(vec[i]);
        else
        {   // 1. Destroy all smaller positive asteroids in its path
            while (!st.empty() && st.top() > 0 && st.top() < abs(vec[i]))
            {
                st.pop();
            }
            // Both explode: pop the positive one, and don't push the negative one
            if (!st.empty() && st.top() > 0 && st.top() == abs(vec[i]))
                st.pop();
            // Safe to push: stack is empty, or the next asteroid is also moving left
            else if(st.empty() || st.top() < 0)
                {
                    st.push(vec[i]);
                }
        }
    }
    return st;
}