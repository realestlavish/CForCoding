#include <bits/stdc++.h>
#include <set>
using namespace std;

set<int> unioncreator(int arr[], int n1, int art[], int n2)
{
    set<int> s;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (arr[i] == art[j])
        {
            s.insert(arr[i]);
            i++;
            j++;
        }
        else if (arr[i] < art[j])
        {
            s.insert(arr[i]);
            i++;
        }
        else
        {
            s.insert(art[j]);
            j++;
        }
    }
    while (i < n1)
    {
        s.insert(arr[i]);
        i++;
    }
    while (j < n2)
    {
        s.insert(art[j]);
        j++;
    }
    return s;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr) / sizeof(arr[0]);

    int art[] = {0, 2, 3, 5, 6, 9};
    int n2 = sizeof(art) / sizeof(art[0]);

    set<int> res = unioncreator(arr, n1, art, n2);
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}
