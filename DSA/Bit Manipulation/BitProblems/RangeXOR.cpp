#include <iostream>
using namespace std;

/*
 * SEQUENTIAL XOR PATTERN (1 to N)
 * -------------------------------
 * N=1 : 1                         = 1 (modulo=1)
 * N=2 : 1 ^ 2                     = 3 (modulo=2)
 * N=3 : 1 ^ 2 ^ 3                 = 0 (modulo=3)
 * N=4 : 1 ^ 2 ^ 3 ^ 4             = 4 (modulo=0)
 * N=5 : 1 ^ 2 ^ 3 ^ 4 ^ 5         = 1 (modulo=1)
 * N=6 : 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6     = 7 (modulo=2)
 * N=7 : 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 = 0 (modulo=3)
 * N=8 : 1 ^ 2 ^ 3 ^ ... ^ 8       = 8 (modulo=0)
 * N=9 :                           = 1 (modulo=1)
 *
 * THE RULE (Based on N modulo 4)
 * -------------------------------
 * The result repeats in cycles of 4:
 *
 * If N % 4 == 1 -> Result is 1
 * If N % 4 == 2 -> Result is N + 1
 * If N % 4 == 3 -> Result is 0
 * If N % 4 == 0 -> Result is N
 */
int xorPattern(int n)
{
    if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else if (n % 4 == 3)
        return 0;
    else
        return 0;
}

int xorRange(int l, int r)
{
    return xorPattern(l - 1) ^ xorPattern(r);
}

int main()
{
    int l = 2;
    int r = 5;
    int result = xorRange(l, r);
    cout << "Result: " << result << endl;
    return 0;
}