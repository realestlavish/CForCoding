
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// decimal to binary converter
void binary_converter(int n)
{
    // first we will check if the number is less than or equal to 0 then we will print 0 and return. otherwise we will keep dividing the number by 2 and storing the remainder in a string. finally we will reverse the string and print it.
    if (n<=0) cout << "0" << endl;
    string s = "";
    while (n >0)
    {
        s+= (n % 2 == 0) ? '0' : '1';
        n /= 2;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}


// binary to decimal converter

void decimal_converter(string s){
    int num=0;
    int power=1;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='1'){
            num+=power;
        }
        power*=2;
    }
    cout << num << endl;
}



int main()
{
    int n = 6;
    binary_converter(n);
    decimal_converter("111");
    return 0;
}