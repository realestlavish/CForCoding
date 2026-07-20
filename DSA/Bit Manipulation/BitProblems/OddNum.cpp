#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> OddbyBit(vector<int> arr)
{
    int res = 0, r1 = 0, r2 = 0;

    for (int num : arr)
    {
        res ^= num;
    }
    // two complement of res done by flipping the bits and adding 1.
    int two_complement_res = (~res) + 1;

    /*the & of res and two_complement_res leaves us with the RSB, the RSB is the bit where the both numbers which appear odd time differ,
    one has 0 and other has 1 as RSB*/
    int set_bit = res & two_complement_res;
    for (int num : arr)
    {
        /*the & of set_bit and num divides the elements into 2 buckets.
        One group where the numbers have the rightmost set bit.
        Another group where the numbers do not have this bit set.
        Perform XOR operations while adding numbers in each group. This will cancel out the duplicate numbers, leaving only the unique numbers in each group*/
        if (set_bit & num)
        {
            r1 ^= num;
        }
        else
            r2 ^= num;
    }
    vector<int> vec = {r1, r2};
    sort(vec.begin(), vec.end());
    return vec;
}

int main()
{
    vector<int> vec = {1, 2, 1, 4, 5, 4};
    vector<int> res = OddbyBit(vec);
    for (int num : res)
    {
        cout << num << " ";
    }
}