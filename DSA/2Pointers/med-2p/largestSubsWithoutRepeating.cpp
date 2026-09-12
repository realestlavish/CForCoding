#include<iostream>
#include<string>
#include<vector>
using namespace std;

int BruteLargestSubstringWithoutRepeating(string s){
    vector<int> hash(256, -1);
    int maxlen=0;
    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++){
            hash[s[j]]=-1;
        }
        for(int j=i;j<s.length();j++){
            if(hash[s[j]]!=-1){
                break;
            }
            hash[s[j]]=j;
            maxlen=max(maxlen,j-i+1);
        }
    }
    return maxlen;
}
int OptimalLargestSubstringWithoutRepeating(string s){
    vector<int> hash(256, -1);
    int l=0,r=0,n=s.length(),maxlen=0;
    while(r<n){
        if(hash[s[r]]!=-1){
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
        }
        maxlen=max(maxlen,r-l+1);
        hash[s[r]]=r;
        r++;
    }
    return maxlen;
}