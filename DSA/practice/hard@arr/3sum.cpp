#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>
threeSum(vector<int> &arr, int n)
{
    // Store unique triplets
    set<vector<int>> st;

    // First loop for first element
    for (int i = 0; i < n; i++)
    {
        // Second loop for second element
        for (int j = i + 1; j < n; j++)
        {
            // Third loop for third element
            for (int k = j + 1; k < n; k++)
            {
                // If triplet sum is zero
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    // Store sorted triplet to avoid duplicates
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    // Convert set to vector
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> betterThreeSum(vector<int> arr)
{
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        set<int> hashset;

        for (int j = i + 1; j < n; j++)
        {
            int third = -(arr[i] + arr[j]);

            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp); // set removes duplicates
            }

            hashset.insert(arr[j]);
        }
    }

    // convert set to vector
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> optimal3sum(vector<int> arr)
{
    vector<vector<int>> vec;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int low = 0; low < n; low++)
    {
        if (low > 0 && arr[low] == arr[low - 1])
        {
            continue;
        }
        int mid = low + 1;
        int high = n - 1;
        while (mid < high)
        {
            int sum = arr[low] + arr[mid] + arr[high];
            if (sum == 0)
            {
                vec.push_back({arr[low], arr[mid], arr[high]});
                mid++;
                high--;

                while (mid < high && arr[mid] == arr[mid - 1])
                    mid++;
                while (mid < high && arr[high] == arr[high + 1])
                    high--;
            }
            if (sum < 0)
            {
                mid++;
            }
            if (sum > 0)
            {
                high--;
            }
        }
    }
    return vec;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = optimal3sum(arr);
    for (auto it : result)
    {
        cout << "[";
        for (int i = 0; i < it.size(); i++)
        {
            cout << it[i];
            if (i < it.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}