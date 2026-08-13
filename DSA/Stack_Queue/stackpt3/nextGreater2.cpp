#include <stack>
#include <vector>
#include <iostream>
using namespace std;

vector<int> nextGreater(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> res(n);

    // Traverse from right to left
    for (int i = (2 * n - 1); i >= 0; i--)
    {

        if (i < n)
        {
            // Pop all smaller or equal elements
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }

            // If stack is empty, no greater element
            if (i < n)
            {
                if (st.empty())
                    res[i] = -1;

                // Else top of stack is the answer
                else res[i] = st.top();
            }
            // Push current element
            st.push(nums[i % n]);
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {5, 7, 1, 7, 6};
    vector<int> ans = nextGreater(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}
