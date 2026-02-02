#include <bits/stdc++.h>
using namespace std;

// for checking anagrams
bool isAnagram(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    int freq[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'A']++;
        freq[s2[i] - 'A']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    string str1 = "CAT";
    string str2 = "ATC";

    if (isAnagram(str1, str2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
