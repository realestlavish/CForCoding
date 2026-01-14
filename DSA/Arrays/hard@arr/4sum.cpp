#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute4Sum(vector<int> &arr, int ks)
{
    set<vector<int>> seen;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if (sum == ks)
                    {
                        vector<int> quad = {arr[i], arr[j], arr[k], arr[l]};
                        sort(quad.begin(), quad.end());
                        seen.insert(quad);
                    }
                }
            }
        }
    }
    vector<vector<int>> res(seen.begin(), seen.end());

    return res;
}

vector<vector<int>> better4Sum(vector<int> &arr, int ks)
{
    set<vector<int>> temp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        set<int> st;
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                long long presum = arr[i];
                presum += arr[j];
                presum += arr[k];
                long long rem = ks - presum;
                if (st.find(rem) != st.end())
                {
                    vector<int> quad = {arr[i], arr[j], arr[k], (int)rem};
                    sort(quad.begin(), quad.end());
                    temp.insert(quad);
                }
                st.insert(arr[k]);
            }
        }
    }

    return vector<vector<int>>(temp.begin(), temp.end());
}

vector<vector<int>> optimal4Sum(vector<int> &arr, int ks)
{
    vector<vector<int>> temp;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
            {
                continue;
            }
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                sum += arr[l];
                if (sum == ks)
                {
                    vector<int> quads = {arr[i], arr[j], arr[k], arr[l]};
                    sort(quads.begin(), quads.end());
                    temp.push_back(quads);
                    k++;
                    l--;
                    while (k < l && arr[k] == arr[k - 1])
                    {
                        k++;
                    }
                    while (k < l && arr[l] == arr[l + 1])
                    {
                        l--;
                    }
                }
                else if (sum > ks)
                {
                    l--;
                }
                else if (sum < ks)
                {
                    k++;
                }
            }
        }
    }

    return vector<vector<int>>(temp.begin(), temp.end());
}

int main()
{
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int ks = 0;
    vector<vector<int>> result = optimal4Sum(arr, ks);
    for (auto quad : result)
    {
        cout << "[";
        for (auto i = 0; i < quad.size(); i++)
        {
            cout << quad[i];
            if (i < quad.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}