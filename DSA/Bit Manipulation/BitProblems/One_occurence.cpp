#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int Sol_occurence(vector<int> vec)
{
    int n = vec.size();
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            return vec[i];
        int first = vec[i];
        int second = vec[i + 1];
        if ((first ^ second) == 0)
        {
            i++;
        }
        else
        {
            return vec[i];
        }
    }
    return 0;
}
 /* XOR cancels out matching numbers (A ^ A = 0) and preserves the unmatched number (A ^ 0 = A)*/
int Sol_occurence2(vector<int> vec) {
    int result = 0;
    for (int num : vec) {
        result ^= num;
    }
    return result;
}
int main()
{
    vector<int> vec = {1,1,5,2,5};
    int res = Sol_occurence2(vec);
    cout << res << endl;
    return 0;
}