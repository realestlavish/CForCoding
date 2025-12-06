#include <bits/stdc++.h>
using namespace std;

void bigboy(vector<int> arr)
{
    int big = INT16_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > big)
        {
            big = arr[i];
        }
    }
    cout << big << " ";
}
int main()
{
    vector<int> arr = {2, 3, 1, 5, 4};
    bigboy(arr);
    return 0;
}