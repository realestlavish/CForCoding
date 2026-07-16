#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void LeftShiftsetBits(int n, int k)
{
    // by Left Shift
    // we will left shift 1 by k bits and then we will do bitwise AND with n. if the result is 0 then the bit is not set otherwise it is set.
    if (n & (1 << k))
    {
        cout << "Bit is already set" << endl;
    }
    else
    {
        cout << "Not Set :" << n << endl;
    }
}

void RightshiftSetBits(int n, int k)
{
    // by Right Shift
    // we will right shift n by k bits and then we will do bitwise AND with 1. if the result is 0 then the bit is not set otherwise it is set.
    if ((n >> k) & 1 == 0)
    {
        cout << "Not Set :" << n << endl;
    }
    else
    {
        cout << "Bit is already set" << endl;
    }
}

int main()
{
    int n = 13;
    int k = 2;
    LeftShiftsetBits(n, k);
    RightshiftSetBits(n, k);
    return 0;
}