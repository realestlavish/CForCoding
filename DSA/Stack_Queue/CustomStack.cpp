#include <stack>
#include <iostream>
using namespace std;

class CustomStack
{
private:
    stack<pair<int, int>> st;

public:
    CustomStack()
    {
    }
    int getMin()
    {
        return st.top().second;
    }
    void push(int x)
    {
        if (st.empty())
        {
            st.push({x, x});
        }
        else
        {
            int minVal = min(x, st.top().second);
            st.push({x, minVal});
        }
    }
    void pop()
    {
        st.pop();
    }
    int top()
    {
        return st.top().first;
    }
};

int main()
{
    CustomStack2 s;

    // Function calls
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.getMin();
}