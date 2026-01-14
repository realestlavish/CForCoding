#include <bits/stdc++.h>
using namespace std;

int bruteksumxor(vector<int>&arr, int k){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xor_value = 0;
            for(int ks=i;ks<j+1;ks++){
                xor_value= xor_value^ arr[ks];
            }
            if(xor_value==k){
                cnt++;
            }
        }
    }
    return cnt;
}

int betterksumxor(vector<int>&arr, int k){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        int xor_value=0;
        for(int j=i;j<n;j++){
            xor_value= xor_value^ arr[j];
            if(xor_value==k){
                cnt++;
            }
        }
    }
    return cnt;
}

int optimalksumxor(vector<int>&arr, int k){
    int n=arr.size();
    int cnt=0;
    unordered_map<int,int> mp;
    int xor_value=0;
    mp[xor_value]++;
    for(int i=0;i<n;i++){
        xor_value= xor_value^ arr[i];
        int rem = xor_value^ k;
        if(mp.find(rem)!=mp.end()){
            cnt+=mp[rem];
        }
        mp[xor_value]++;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    
    cout << bruteksumxor(arr, k) << endl;
    cout << betterksumxor(arr, k) << endl;
    cout << optimalksumxor(arr, k) << endl;
    
    return 0;
}