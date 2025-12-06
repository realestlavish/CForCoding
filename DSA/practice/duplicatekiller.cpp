#include <bits/stdc++.h>
using namespace std;

void duplicatekiller(vector<int> arr)
{
    int i = 0;
    while (i < arr.size() - 2)
    {
        if (arr[i] != arr[i + 1])
        {
            i++;
        }
        else
        {
            int index = i + 1;
            arr.erase(arr.begin() + index);
        }
    }
    for (int j = 0; j < arr.size(); j++)
    {
        cout << arr[j] << " ";
    }
    cout << "original elements are " << arr.size() << endl;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 2, 2, 3, 3, 8, 8, 9, 10};
    duplicatekiller(arr);

    return 0;
}