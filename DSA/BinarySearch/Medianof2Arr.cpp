#include <bits/stdc++.h>
using namespace std;

double basicmerge(int arr1[], int n1, int arr2[], int n2)
{
    vector<int> temp;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] > arr2[j])
        {
            temp.push_back(arr2[j]);
            j++;
        }
        else
        {
            temp.push_back(arr1[i]);
            i++;
        }
    }
    while (i < n1)
        temp.push_back(arr1[i++]);
    while (j < n2)
        temp.push_back(arr2[j++]);

    int tsize = temp.size();
    if (tsize % 2 != 0)
        return temp[((tsize + 1) / 2) - 1];
    else
    {
        int index = tsize / 2;
        double median = (temp[index] + temp[index - 1]) / 2.0;
        return median;

        return 0;
    }
}

double bettermerge(int arr1[], int n1, int arr2[], int n2)
{
    int i = 0, j = 0;
    int cnt = 0;
    int n = n1 + n2;
    int ind1 = -1, ind2 = -1;
    int elind1 = n / 2 - 1, elind2 = n / 2;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            if (cnt == elind1)
                ind1 = arr1[i];
            if (cnt == elind2)
                ind2 = arr1[i];
            cnt++;
            i++;
        }
        if (arr1[i] > arr2[j])
        {
            if (cnt == elind1)
                ind1 = arr2[j];
            if (cnt == elind2)
                ind2 = arr2[j];
            cnt++;
            j++;
        }
    }
    while (i < n1)
    {
        if (cnt == elind1)
            ind1 = arr1[i];
        if (cnt == elind2)
            ind2 = arr1[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == elind1)
            ind1 = arr2[j];
        if (cnt == elind2)
            ind2 = arr2[j];
        cnt++;
        j++;
    }
    if (n % 2 != 0)
        return ind2;
    else
        return (ind1 + ind2) / 2.0;
}

double binarysearch(int arr1[], int n1, int arr2[], int n2)
{
    int low = 0;
    int high = min(n1, n2);
    int left = (n1 + n2 + 1) / 2; // formula for no. of left side symmetry elements
    int n = n1 + n2;
    while (low <= high)
    {
        int mid1 = low + high / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MIN, r2 = INT_MIN;
        if (mid1 < n1)
            r1 = arr1[mid1];
        if (mid2 < n2)
            r2 = arr2[mid2];
        if (mid1 - 1 >= 0)
            l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = arr2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return max(l1, l2);
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
}

int main()
{
    int n1 = 3;
    int arr1[] = {2, 4, 6};
    int n2 = 3;
    int arr2[] = {1, 3, 5};

    // double result1 = basicmerge(arr1, n1, arr2, n2);
    // cout << "Basic merge result: " << result1 << endl;

    double result2 = bettermerge(arr1, n1, arr2, n2);
    cout << " merge result: " << result2 << endl;

    double result3 = binarysearch(arr1, n1, arr2, n2);
    cout << "Binary search result: " << result3 << endl;

    return 0;
}
