#include <bits/stdc++.h>
using namespace std;

bool comparator(const pair<int, char> &p1, const pair<int, char> &p2)
{
    if (p1.first != p2.first)
        return p1.first > p2.first;

    return p1.second < p2.second;
}

vector<char> FreqFinder(string s)
{
    pair<int, char> freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = {0, i + 'a'};
    }
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a'].first++;
    }
    sort(freq, freq + 26, comparator);
    vector<char> sm;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i].first > 0)
            sm.push_back(freq[i].second);
    }

    return sm;
}

int main()
{
    string str1 = "tree";
    vector<char> ss = FreqFinder(str1);
    for (int i = 0; i < ss.size(); i++)
    {
        cout << ss[i];
    }

    return 0;
}
