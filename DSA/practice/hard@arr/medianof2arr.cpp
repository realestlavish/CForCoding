#include <bits/stdc++.h>
#include <set>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0;
    int j = 0;
    vector<int> temp;
    while (i < n1 && j < n2)
    {
        if (nums1[i] > nums2[j])
        {
            temp.push_back(nums2[j]);
            j++;
        }
        else
        {
            temp.push_back(nums1[i]);
            i++;
        }
    }
    while (i < n1)
    {
        temp.push_back(nums1[i]);
        i++;
    }
    while (j < n2)
    {
        temp.push_back(nums2[j]);
        j++;
    }
    int z = temp.size();
    double median;

    if (z % 2 == 1)
    {
        median = temp[z / 2];
    }
    else
    {
        median = (temp[z / 2] + temp[(z / 2) - 1]) / 2.0;
    }

    return median;
}

int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    findMedianSortedArrays(nums1, nums2);
    return 0;
}
