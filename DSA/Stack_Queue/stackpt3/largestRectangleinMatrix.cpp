#include <stack>
#include <vector>
#include <iostream>
using namespace std;

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

int largestRectangleinMatrix(vector<vector<int>> vec)
{
    int n = vec[0].size();
    int m = vec.size();
    int maxArea = 0;
    vector<int> vexy(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vec[i][j] == 1)
            {
                vexy[j]++;
            }
            else
                vexy[j] = 0;
        } 
        maxArea = max(maxArea, optimumlargestRectangle(vexy));
    }
    return maxArea;
}
int main()
{
    vector<vector<int>> heights = {{1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};
    cout << "Optimized: " << largestRectangleinMatrix(heights) << '\n';

    return 0;
}