#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int SetBits(int n, int i)
{
    //first we will left shift 1 by i bits and then we will do bitwise OR with n.
    return (n | (1 << i));
}

int main()
{
    int n = 14;
    int i = 2;
    int result = SetBits(n, i);
    cout << "Result: " << result << endl;
    return 0;
}