#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int powerOf2(int n)
{
    //every even number has 1 set bit at the end, so if we remove that set bit and the number becomes 0, then it is a power of 2.
    if ((n & n - 1) == 0)cout << n << " is a power of 2" << endl;
    else  cout << n << " is not a power of 2" << endl;
}

int main()
{
    int n = 14;
    int result = powerOf2(n);
    cout << "Result: " << result << endl;
    return 0;
}