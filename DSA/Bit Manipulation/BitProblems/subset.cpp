#include <vector>
#include<iostream>
using namespace std;

vector<vector<int>> getPowerSet(vector<int> &nums)
{
    int n = nums.size();

    // Calculate the total number of subsets (2^n) using bitwise shift
    int subsets = 1 << n;

    vector<vector<int>> ans;

    // Iterate through all numbers from 0 to 2^n - 1
    for (int num = 0; num < subsets; num++)
    {
        // Temporary vector to hold the current subset
        vector<int> subset;

        // Iterate through each bit of the number
        for (int i = 0; i < n; i++)
        {
            // If the ith bit is set, include nums[i] in the subset
            if (num & (1 << i))
            {
                subset.push_back(nums[i]);
            }
        }
        // Add the constructed subset into the result
        ans.push_back(subset);
    }

    // Return all subsets
    return ans;
}

int main()
{
    vector<int> nums = {5, 7, 8};

    // Call function to generate subsets
    vector<vector<int>> subsets = getPowerSet(nums);

    // Print original input array
    cout << "Initial Input Array: ";
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    // Print all subsets
    cout << "Subsets: " << endl;
    for (auto subset : subsets)
    {
        cout << "[ ";
        for (auto num : subset)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
