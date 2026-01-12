#include <bits/stdc++.h>
#include <utility>
using namespace std;

void mergewithoutspace1(int arr1[], int arr2[], int n, int m)
{
    int arr3[n + m];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }
    while (i < n)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j < m)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
        {
            arr1[i] = arr3[i];
        }
        else
        {
            arr2[i - n] = arr3[i];
        }
    }
}

void mergewithoutspace2(int arr1[], int arr2[], int n, int m)
{
    int low=n-1;
    int high=0;
    while (low>=0 && high < m) {
        if (arr1[low]>arr2[high]) {
            swap(arr1[low],arr2[high]);
            low--;
            high++;
        }
        else {
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}


void shellsort(int arr1[], int arr2[], int n, int m)
{
    int len = n+m;
    int gap = (len /2)+ (len% 2);
    while (gap>0) {
        int left=0;
        int right =left+gap;
        while (right < len)
        {
            if (left < n && right >= n)
            {
                if (arr1[left] > arr2[right - n])
                {
                    swap(arr1[left], arr2[right - n]);
                }
            }
            else if (left >= n)
            {
                if (arr2[left - n] > arr2[right - n])
                {
                    swap(arr2[left - n], arr2[right - n]);
                }
            }
            else
            {
                if (arr1[left] > arr1[right])
                {
                    swap(arr1[left], arr1[right]);
                }
            }
            left++;
            right++;
        }
    if (gap==1) {
    break;
    }
    gap = (len /2)+ (len% 2);
}
}

int main()
{
    int nums1[] = {-5, -2, 4, 5, 0, 0, 0};
    int nums2[] = {-3, 1, 8};
    int n = 7;
    int m = 3;
    mergewithoutspace1(nums1, nums2, n, m);
    mergewithoutspace2(nums1, nums2, n, m);
    return 0;
}
