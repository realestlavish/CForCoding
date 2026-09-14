#include <vector>
#include <algorithm>
using namespace std;

int maxConsecutiveOnes(vector<int> &arr, int k)
{
    int n = arr.size();
    int left = 0;
    int right = 0;
    int maxCount = 0;
    int zeroCount = 0;
    int cnt = 0;
    while (right < n)
    {
        if (arr[right] == 0)
        {
            zeroCount++;
        }
        while (zeroCount > k)
        {
            if (arr[left] == 0)
            {
                zeroCount--;
            }
            left++;
        }
        maxCount = max(maxCount, right - left + 1);
        right++;
    }
    return maxCount;
}