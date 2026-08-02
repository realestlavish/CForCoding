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

// Class to implement Minimum Stack
class MinStack {
private:
    stack <int> st;
    int mini;
    
public:
    
    MinStack() {
    }
    
    void push(int value) {
        
        // If stack is empty
        if(st.empty()) {
            //Update the minimum value
            mini = value;
            
            // Push current value as minimum
            st.push( value );
            return;
        }
        
        // If the value is greater than the minimum
        if(value > mini) {
            st.push(value);
        }
        else {
            // If the value is smaller than the minimum
            // Add the modified value to stack
            st.push(2 * value - mini);
            // Update the minimum
            mini = value;
        }
    }

    void pop() {
        if(st.empty()) return;
        
        // Get the top
        int x = st.top();
        st.pop(); // Pop operation
        
        // If the modified value was added to stack
        if(x < mini) {
            // Update the minimum
            // rollback to previous minimum
            mini = 2 * mini - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        
        int x = st.top();
        // Returnn top if minimum is less than the top (it is not a modified value)
        if(mini < x) return x;
        
        //Otherwise return mini
        return mini;
    }
    
    int getMin() {
        // Return the minimum
        return mini;
    }
};

int main() {
    MinStack s;
    
    // Function calls
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.getMin();
    
    return 0;
}

int main()
{
    MinStack s;

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