#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int subarrRangeSum1(vector<int> vec)
{
    int total = 0;
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        int largest = vec[i], smallest = vec[i];
        for (int j = i; j < n; j++)
        {
            largest = max(largest, vec[j]);
            smallest = min(smallest, vec[j]);
            total += (largest - smallest);
        }
    }
    return total;
}

vector<int> nse(vector<int> vec)
{
    stack<int> st;
    vector<int> nse(vec.size());
    int n = vec.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && vec[st.top()] >= vec[i])
        {
            st.pop();
        }

        nse[i] = st.empty() ? n : st.top();
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

vector<int> pgee(vector<int> vec)
{
    stack<int> st;
    vector<int> pgee(vec.size());
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && vec[st.top()] < vec[i])
        {
            st.pop();
        }

        pgee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pgee;
}
vector<int> ngee(vector<int> vec)
{
    stack<int> st;
    vector<int> ngee(vec.size());
    int n = vec.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && vec[st.top()] <= vec[i])
        {
            st.pop();
        }

        ngee[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ngee;
}

long long minSubArray(vector<int> vec){
    long long totalsum = 0;
    int n=vec.size();
    vector<int> left=pse(vec);
    vector<int> right = nse(vec);
    for (int i = 0; i < n; i++)
    {
        int lefty= i-left[i];
        int righty= right[i]-i;
        totalsum += 1LL * righty * lefty * vec[i];
    }
    return totalsum;
}

long long maxSubArray(vector<int> vec){
    long long totalsum = 0;
    vector<int> left=pgee(vec);
    int n=vec.size();
    vector<int> right = ngee(vec);
    for (int i = 0; i < n; i++)
    {
        int lefty= i-left[i];
        int righty= right[i]-i;
        totalsum += 1LL * righty * lefty * vec[i];
    }
    return totalsum;
}
long long subarrRangeSum2(vector<int> vec)
{
    return maxSubArray(vec)-minSubArray(vec);
}

int main()
{
    vector<int> vec = {1, 2, 3};
    int res = subarrRangeSum2(vec);
    cout << res;
}