#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int RemoveLastSetBits(int n)
{
    /*Step 1: The Flip (n - 1) Subtracting 1 forces the rightmost 1 to become a 0, and flips all the 0s to its right into 1s.
    Step 2: The Wipeout (&) When you AND the original number with this new number, the bits on the left match and are saved. However, the rightmost 1 and everything to its right are now exact opposites—so the AND operation cancels them all out to 0.\
    Final : The bits on the left survive, but the last 1 is erased!*/
    return (n & n - 1);
}

int main()
{
    int n = 14;
    int result = RemoveLastSetBits(n);
    cout << "Result: " << result << endl;
    return 0;
}