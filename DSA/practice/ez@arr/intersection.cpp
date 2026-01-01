#include <bits/stdc++.h>
using namespace std;

void intersectioner(int arr1[], int n1, int arr2[], int n2)
{
    map<int, int> mp1;
    map<int, int> mp2;
    set<int> s;

    for (int i = 0; i < n1; i++)
    {
        mp1[arr1[i]]++;
    }

    for (int i = 0; i < n2; i++)
    {
        mp2[arr2[i]]++;
    }

    for (auto it : mp1)
    {
        if (mp2.find(it.first) != mp2.end())
        {
            s.insert(it.first);
        }
    }

    for (auto it : s)
    {
        cout << it << endl;
    }
}

int main()
{
    int arr1[] = {1, 0, 2, 3, 0, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 3, 5, 6, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    intersectioner(arr1, n1, arr2, n2);
    return 0;
}
