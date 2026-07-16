#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int ToggleBits(int n, int i)
{
    //first we will left shift 1 by i bits and then we will do bitwise XOR with n. this will toggle the bit at position i in n.
    return (n ^ (1 << i));
}

int main()
{
    int n = 14;
    int i = 2;
    int result = ToggleBits(n, i);
    cout << "Result: " << result << endl;
    return 0;
}