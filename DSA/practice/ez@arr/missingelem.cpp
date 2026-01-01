#include <bits/stdc++.h>
using namespace std;

int missingelem(int arr[], int n)
{
    int i=1;
    while (i<=n) {
        if(arr[i-1]!= i){
            return i;
        }
        i++;
    }
    return n +1;
}

int main(){
    int arr[] = {1,2,3,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = missingelem(arr, n);
    cout << res << endl;
   return 0;
}