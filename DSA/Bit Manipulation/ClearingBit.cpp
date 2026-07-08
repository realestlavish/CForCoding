#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
    
int ClearBits(int n, int i)
{
    //first we will left shift 1 by i bits and then take the complement (flip the bits) of it and then we will do bitwise AND with n.
    return (n & (~(1 << i)));
}

int main()
{
    int n = 14;
    int i = 2;
    int result = ClearBits(n, i);
    cout << "Result: " << result << endl;
    return 0;
}