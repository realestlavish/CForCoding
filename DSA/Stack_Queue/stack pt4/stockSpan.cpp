#include <stack>
#include <vector>
#include <iostream>
using namespace std;

vector<int> stockSpan(vector<int> vec)
{
    int n = vec.size();
    vector<int> span(n, 1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && vec[i] >= vec[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            span[i] = i + 1;
        }
        else
            span[i] = i - st.top();

        st.push(i);
    }

    return span;
}

int main()
{
    int n = 7;
    vector<int> arr = {120, 100, 60, 80, 90, 110, 115};

    cout << "n = " << n << ", arr = [";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ", ";
    }
    cout << "]\n";

    vector<int> result = stockSpan(arr);
    cout << "Stock spans: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}