#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

void Combo2( int index,string digits,vector<string> &vec, string &s,string combos[])
{
    if(index==digits.size())
    {
        vec.push_back(s);
        return;
    }
    int digit = digits[index]-'0';
    string letters = combos[digit];
    for(int i=0; i<letters.size(); i++)
    {
        Combo2(index+1,digits,vec,s + combos[digit][i],combos);
    }
}

vector<string> manager(string digits)
{
    string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans; // Vector to store results
    string s = "";      // Temporary string to build combinations
    // Initiate recursive function
    func(0, digits, s, ans, combos);
    return ans; // Return the result
}
int main()
{
    string digits = "23";
    vector<string> ans = manager(digits);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}