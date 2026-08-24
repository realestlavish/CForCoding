#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> nse(vector<int> arr)
{
    stack<int> st;
    vector<int> nse(arr.size());
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
            nse[i] = st.top();
        else
            nse[i] = n;

        st.push(i);
    }
    return nse;
}

vector<int> pse(vector<int> vec)
{
    stack<int> st;
    vector<int> pse(vec.size());
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && vec[st.top()] > vec[i])
        {
            st.pop();
        }

        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}

int brutelargestRectangle(vector<int> arr)
{
    vector<int> psevec = pse(arr);
    vector<int> nsevec = nse(arr);
    int maxArea = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, (arr[i] * (nsevec[i] - psevec[i] - 1)));
    }
    return maxArea;
}

int optimumlargestRectangle(vector<int> arr)
{

    int maxArea = 0;
    int nse = 0, pse = 0;
    stack<int> st;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            int heightIndex = st.top();
            st.pop();
            nse = i;
            pse = (!st.empty()) ? st.top() : -1;
            maxArea = max(maxArea, (arr[heightIndex] * (nse - pse - 1)));
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int heightIndex = st.top();
        st.pop();
        nse = n;
        pse = (!st.empty()) ? st.top() : -1;
        maxArea = max(maxArea, (arr[heightIndex] * (nse - pse - 1)));
    }

    return maxArea;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Brute force: " << brutelargestRectangle(heights) << '\n';
    cout << "Optimized: " << optimumlargestRectangle(heights) << '\n';

    return 0;
}