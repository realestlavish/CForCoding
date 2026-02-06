#include <bits/stdc++.h>
using namespace std;

void reverseString(string &s, int start, int end)
{
    while (start < end)
    {
        swap(s[start++], s[end--]);
    }
}
string reverseWords(string s)
{
    int n = s.length();
    reverseString(s, 0, n - 1);

    int i = 0, j = 0, start = 0, end = 0;

    while (j < n)
    {
        // Skipspaces
        while (j < n && s[j] == ' ')
            j++;
        if (j == n)
            break;

        start = i;

        // Copy the word characters forward
        while (j < n && s[j] != ' ')
        {
            s[i++] = s[j++];
        }

        end = i - 1;

        // Reverse the current word using start and end
        reverseString(s, start, end);
        cout<<"test2 "<< s <<endl;

        // Add a space after the word if it's not the last word
        if (j < n)
        {
            s[i++] = ' ';
        }
    }

    // Remove trailing space if present
    if (i > 0 && s[i - 1] == ' ')
        i--;

    return s.substr(0, i);
}

int main()
{
    string s = " coding is amazing ";
    string ans = reverseWords(s);
    cout << "Input string: " << s << endl;
    cout << "After reversing every word: " << ans << endl;
}