#include <bits/stdc++.h>
using namespace std;

int SubStringcnthelper(string s, int k)
{
    int n = s.length();
    int left = 0, tempstring=0;
    unordered_map<char, int> freqmp;
    for (int right = 0; right < n; right++)
    {
        freqmp[s[right]]++;

        while (freqmp.size() > k)
        {
            freqmp[s[left]]--;
            if (freqmp[s[left]] == 0)
            {
                freqmp.erase(s[left]);
            }
            left++;
        }
        tempstring += right - left + 1;
    }
    return tempstring;
}

int substringswithKelements(string s, int k){
    return SubStringcnthelper(s,k)-SubStringcnthelper(s,k-1);
}
int main()
{
    string str1 = "pqpqs";
    int k = 2;

    int ss = substringswithKelements(str1, k);
    cout << ss;

    return 0;
}
