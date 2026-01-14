#include <bits/stdc++.h>
#include <set>
using namespace std;

int elembrute(int arr[],int n1){
    for (int i = 0; i < n1; i++)
    {
        int num= arr[i];
        int cnt=0;

        for (int j = 0; j < n1; j++)
        {
            if(arr[j]==num){
                cnt++;
            }
        }
        if(cnt==1){
            return num;
        }
    }
    
}


int elembetter(int arr[], int n1)
{
    map<int,int> mpp;
    for (int i = 0; i < n1; i++)
    {
        mpp[arr[i]]++;
    }

    for(auto it:mpp){
        if(it.second==1){
            return it.first;
        }   
    }
    
}


int elemoptimal(int arr[], int n1)
{
    int xory=0;
    for (int i = 0; i < n1; i++)
    {
        xory = xory ^ arr[i];
    }
    return xory;
}



int main()
{
    int arr[] = {1,1,2,2,3,3,5,5,4};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    int res = elembetter(arr,n1);
    int res2 = elembrute(arr,n1);
    int res3 = elemoptimal(arr,n1);
    cout<< res << " " << res2 << " " << res3;
    return 0;
}
