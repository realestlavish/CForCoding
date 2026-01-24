#include <bits/stdc++.h>
using namespace std;

int missingbinary(vector<int> &vec, int k, int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = vec[mid] - vec[0] - mid; 

        if (missing < k)
        {
            low = mid + 1; 
        }
        else high = mid - 1; 
    }
    return low + k;
}
//when high goes lesser than low, the missing number is at right of the high,so we add the MORE(k-missing) to high to find the exact number.
//we use low+k or we can use high+1+k both are same, low and high go to opposite polarity, ans = vec[high]+more, more = k-(missing till high).

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int k = 4;
    int n = vec.size();

    // Call the function
    int result = missingbinary(vec, k, n);
    cout << "Result: " << result << endl;

    return 0;
}
