#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



int countSetBit1(int n)
{// Uses Brian Kernighan's algorithm: each iteration clears the lowest set bit.
 // Working:
 //   n = 13 (binary 1101)
 //   iteration 1: n = 1101 & 1100 = 1100, count = 1
 //   iteration 2: n = 1100 & 1011 = 1000, count = 2
 //   iteration 3: n = 1000 & 0111 = 0000, count = 3
 //   loop ends, returns 3.
    int count=0;
    while(n!=0){
       n=n&(n-1);
       count++;
    }
    return count;
}

int countSetBit2(int n)
{
    int count=0;
    while(n>1){
        if(n&1)count++;
        n=n>>1;
    }
    return count;
}

int countSetBit3(int n)
{
    int count=0;
    while(n>1){
        if(n%2==1)count++;
        n=n/2;
    }
    return count;
}
    
int main()
{
    int n = 13;
    int result = countSetBit1(n);
    cout << "Result: " << result << endl;
    return 0;
}