#include <bits/stdc++.h>
#include <set>
using namespace std;

int sumtok(int arr[], int n1)
{
    int maxi=0;
    int tempr = 0;
    for (int i = 0; i < n1; i++)
    {
        if (arr[i]==1)
        {
            maxi+=1;
        }
        else maxi=0;

        if (maxi>tempr){
            tempr=maxi;
        }
    }
    return tempr;
}

int main()
{
    int arr[] = {1,1,1,1};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    int res = sumtok(arr,n1);
    cout<< res;
    return 0;
}
