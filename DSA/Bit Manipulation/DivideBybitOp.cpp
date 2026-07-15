#include <iostream>
using namespace std;

int bitsDivide(int dividend, int divisor)
{
    if (dividend == divisor)
        return 1;
    int cnt = 0;
    long ans = 0;
    bool sign = true;
    long divd = abs(dividend);
    long divs = abs(divisor);
    if (divd >= 0 && divs < 0)
        sign = false;
    if (divs >= 0 && divd < 0)
        sign = false;

    while (divd >= divs)
    {
        cnt = 0;
        while (divd >= (divs << cnt + 1))
        {
            cnt++;
        }
        ans += (1 << cnt);
        divd = divd - (divs << cnt);
    }
    if (ans >= INT_MAX && sign == true)
        return INT_MAX;
    if (ans < INT_MAX && sign == false)
        return INT_MIN;
    return sign ? ans : (-1 * ans);
}