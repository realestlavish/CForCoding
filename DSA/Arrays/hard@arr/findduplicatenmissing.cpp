#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicateAndMissingBruteMethod(vector<int> &nums)
{
    int n = nums.size();
    int el = -1;
    int missing = -1;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == i)
            {
                cnt++;
            }
        }
        if (cnt == 2)
        {
            el = i;
        }
        else if (cnt == 0)
        {
            missing = i;
        }
    }
    return {el, missing};
}

vector<int> findDuplicateAndMissingBetterMethod(vector<int> &nums)
{
    int n = nums.size();
    int el = -1;
    int missing = -1;
    int hash[n + 1] = {0};
    for (int i = 0; i <= n; i++)
    {
        hash[nums[i]]++;
    }
    for (int j = 0; j <= n; j++)
    {
        if (hash[j] == 2)
        {
            el = j;
        }
        else if (hash[j] == 0)
        {
            missing = j;
        }
    }

    return {el, missing};
}

vector<int> findDuplicateAndMissingMethod3(vector<int> &nums)
{
    int n = nums.size();
    int el = -1;
    int missing = -1;
    long long Sn = 0, S = 0, S2n = 0, S2 = 0;
    for (int i = 0; i <= n; i++)
    {
        Sn += i;
        S2n += (i * i);
        S += nums[i];
        S2 += (nums[i] * nums[i]);
    }
    int rem1 = Sn - S;
    int rem2 = S2n - S2;
    int rem3 = rem2 / rem1;
    missing = (rem3 + rem1) / 2;
    el = missing - rem1;
    return {el,missing};
}

int main()
{
    vector<int> nums = {3,vhjgjhghjjhgvxcgj5,4,1,1};
    vector<int> result1 = findDuplicateAndMissingBruteMethod(nums);
    vector<int> result2 = findDuplicateAndMissingBetterMethod(nums);
    vector<int> result3 = findDuplicateAndMissingMethod3(nums);
    cout << "Method1 results: ";
    for (int v : result1)
        cout << v << " ";
    cout << "\n";
    cout << "Method2 results: ";
    for (int v : result2)
        cout << v << " ";
    cout << "\n";
    cout << "Method3 results: ";
    for (int v : result3)
        cout << v << " ";
    cout << "\n";
    return 0;
}
