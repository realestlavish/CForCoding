#include <bits/stdc++.h>
using namespace std;

// to write a recursive function, first apply the base case at which the function becomes invalid/stops, then write the body of the function and then in them apply the conditions.

int RecursiveBS(vector<int> arr,int n,int low,int high,int target){
    if (low>high)  return -1;
    int mid =low+(high-low)/2;
    if(target == arr[mid]) return mid; 
    else if (target>arr[mid]) return RecursiveBS(arr,n,mid+1,high,target);
    return RecursiveBS(arr,n,low,mid-1,target);
}