#include <bits/stdc++.h>
using namespace std;

void secondbigboy(vector<int> arr)
{
    int big = INT16_MIN;
    int second_big = INT16_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > big)
        {
            second_big = big;
            big = arr[i];
        }
        else if (arr[i] > second_big && arr[i] != big)
        {
            second_big = arr[i];
        }
    }
    cout << "Current biggest: " << big << ", Current second biggest: " << second_big << endl;
}

void secondsmallboy(vector<int> arr)
{
    int small = INT16_MAX;
    int second_small = INT16_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < small)
        {
            second_small = small;
            small = arr[i];
        }
        else if (arr[i] < second_small && arr[i] != small)
        {
            second_small = arr[i];
        }
    }
    cout << "Current smallest: " << small << ", Current second smallest: " << second_small << endl;
}
int main()
{
    vector<int> arr = {2, 3, 1, 5, 4};
    secondbigboy(arr);
    secondsmallboy(arr);
    return 0;
}