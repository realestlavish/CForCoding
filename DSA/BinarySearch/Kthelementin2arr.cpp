#include <bits/stdc++.h>
using namespace std;

double betterKin2(vector<int> arr1, vector<int> arr2, int k)
{
    int n1 = arr1.size(), n2 = arr2.size();
    int i = 0, j = 0;
    int cnt = 0;
    int ind1 = -1;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            if (cnt == k - 1)
                ind1 = arr1[i];
            cnt++;
            i++;
        }
        if (arr1[i] > arr2[j])
        {
            if (cnt == k - 1)
                ind1 = arr2[j];
            cnt++;
            j++;
        }
    }
    while (i < n1)
    {
        if (cnt == k - 1)
            ind1 = arr1[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == k - 1)
            ind1 = arr2[j];
        cnt++;
        j++;
    }
    return ind1;
}

double binaryKin2(vector<int> arr1, vector<int> arr2, int k)
{
    if (arr1.size() > arr2.size())
        return binaryKin2(arr2, arr1, k);
    int n1 = arr1.size(), n2 = arr2.size();
    int low = max(0,k-n2);
    int high = min(k,n1);
    int left = k;
    int n = n1 + n2;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = arr1[mid1];
        if (mid2 < n2)
            r2 = arr2[mid2];
        if (mid1 - 1 >= 0)
            l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = arr2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1)
            return max(l1, l2);
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return -1;
}

int main()
{
    vector<int> arr1 = {100, 112, 256, 349, 770};
    vector<int> arr2 = {72, 86, 113, 119, 265, 445, 892};
    int k = 7;

    double result2 = betterKin2(arr1, arr2, k);
    cout << " merge result: " << result2 << endl;

    double result3 = binaryKin2(arr1, arr2, k);
    cout << "Binary search result: " << result3 << endl;

    return 0;
}
