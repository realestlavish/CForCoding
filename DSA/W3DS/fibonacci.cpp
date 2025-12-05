#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n1)
{
    if (n1 <= 1)
        return n1;
    return fibonacci(n1 - 1) + fibonacci(n1 - 2);
}

int main()
{
    int res = 0;
    res = fibonacci(5);
    cout << res << endl;

    return 0;
}