# include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void SwapBits(int a, int b){
    // Swapping using XOR
    cout << "Before Swap : a = " << a << " b = " << b << endl;
    a=a^b;
    b=a^b;
    a=a^b;
    cout << "After Swap : a = " << a << " b = " << b << endl;
}




int main()
{
    int n=5; 
    int k = 6;
    SwapBits(n,k);
    return 0;
}