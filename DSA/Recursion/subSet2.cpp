#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

void SubSets2(vector<int> arr, vector<vector<int>> &vec, vector<int> &ans, int index, int n)
{
    if (index >= n)
    {
        vec.push_back(ans);
        return;
    }
    ans.push_back(arr[index]);
    SubSets2(arr, vec, ans, index + 1, n);
    ans.pop_back();
    SubSets2(arr, vec, ans, index+1, n);
}
vector<vector<int>> manager(vector<int> arr)
{
    vector<vector<int>> vec;
    vector<int> ans;
    int n = arr.size();
    int index = 0;
    SubSets2(arr, vec, ans,index, n);
    return vec;
}
int main()
{
    vector<int> arr = {5, 2, 1};
    vector<vector<int>> ans = manager(arr);
    for (const vector<int> &subset : ans)
    {
        for (const int &val : subset)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}