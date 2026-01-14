#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string res = "";
    sort(strs.begin(), strs.end());
    int n = strs.size();
    if (n == 0)
        return " ";
    if (n == 1)
        return strs[0];
    // first word to compare w everyone else.
    for (int i = 0; i < strs[0].size(); i++)
    {
        // first letter
        char temp = strs[0][i];
        bool check = false;
        for (int j = 0; j < n; j++)
        {
            if (temp == strs[j][i])
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            res += temp;
        }
        else
        {
            break;
        }
    }
    return res;
}
int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    string result = longestCommonPrefix(strs);
    cout << result << endl;
    return 0;
}