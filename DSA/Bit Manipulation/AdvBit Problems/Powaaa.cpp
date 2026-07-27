#include <iostream>
using namespace std;

double more_powaaa(double x, int n)
{
    if (n == 0)
        return 1.0;
    if (n == 1)
        return x;
    if (n % 2 == 0)
    {   // reduced by log n in case of even
        return more_powaaa(x * x, n / 2);
    }
    else
        // in case of odd, we first convert poweer into even by doing -1 from power.
        return x * (more_powaaa(x, n - 1));
}
double myPow(double x, int n)
{
    // Store the value of n in a separate variable
    int num = n;

    // If n is negative
    if (num < 0)
    {
        // Calculate the power of -n and take reciprocal
        return (1.0 / more_powaaa(x, -1 * num));
    }
    // If n is non-negative
    return more_powaaa(x, num);
}
int main()
{
    double x = 2.0;
    int n = 9;
    double rees = myPow(x, n);
    cout << rees;
    return 0;
}