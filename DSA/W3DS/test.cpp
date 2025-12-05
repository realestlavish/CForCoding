#include <bits/stdc++.h>
using namespace std;

long long sumAndMultiply(int n)
{
    long long sum = 0;
    long long result = 0;
    string ns = to_string(n);
    string s = "";
    for (char c : ns)
    {
        if (c == '0')
            continue;
        s += c;
        sum += c - '0';
    }

    if (s.empty())
    {
        return 0;
    }
    result = stoll(s);
    long long finalres = 0;
    finalres = result * sum;
    return finalres;
};

int main()
{
    long long n = 6523002540520;
    cout << sumAndMultiply(n) << endl;
    return 0;
}