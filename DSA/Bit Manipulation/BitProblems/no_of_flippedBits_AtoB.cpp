#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 1st Solution
string binary_converter(int n)
{
    // first we will check if the number is less than or equal to 0 then we will print 0 and return. otherwise we will keep dividing the number by 2 and storing the remainder in a string. finally we will reverse the string and print it.
    if (n <= 0)
        cout << "0" << endl;
    string s = "";
    while (n > 0)
    {
        s += (n % 2 == 0) ? '0' : '1';
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int no_of_flippedBits_AtoB(int a, int b)
{
    string binary_A = binary_converter(a);
    string binary_B = binary_converter(b);
    int cnt = 0;
    int length_A = binary_A.length();
    int length_B = binary_B.length();
    int limit = (length_A > length_B) ? length_A : length_B;
    for (int i = 0; i < limit; i++)
    {
        char comp_A = (i < length_A) ? binary_A[length_A - i - 1] : '0';
        char comp_B = (i < length_B) ? binary_B[length_B - i - 1] : '0';
        if (comp_A != comp_B)
            cnt++;
    }
    return cnt;
}

// Fast Solution
int aTOb_flippedBits(int start, int goal)
{
    /* the XOR leaves us with the bits (1) that need to be counted (bits that need to be flipped to convert A to B). then (num & 1) checks if the RSB ==1, if it is ==1 then, the & operation gives us 1, which is added to cnt. and right shift operation replaces the last Bit to compare with next LSB.*/i
    int num = (start ^ goal);
    int cnt = 0;
    for (int i = 0; i < 32; i++)
    {
        cnt += (num & 1);
        num >>= 1;
    }
    return cnt;
}

int main()
{
    int start = 3;
    int end = 15;
    int res1 = no_of_flippedBits_AtoB(start, end);
    int res2 = aTOb_flippedBits(start, end);
    cout << res1 << endl;
    cout << res2 << endl;
    return 0;
}