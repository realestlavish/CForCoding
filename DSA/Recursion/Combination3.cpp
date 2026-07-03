#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;



void SubSets(vector<vector<int>> &vec,int sum,int index,int n,int k,vector<int>&temp){
    if(sum==0 && temp.size()==k){
        vec.push_back(temp);
        return;
    }
    if(sum <= 0 || temp.size() > k) return; 

    for(int ind=index;ind<=9;ind++){
        if(ind>sum) break;

        else{
        
        temp.push_back(ind);
        SubSets(vec,sum-ind,ind+1,k,temp);
        temp.pop_back();
    }}
   
}



vector<vector<int>> manager(int n, int k){
    vector<vector<int>> vec;
    int sum=0;
    int index=1;
    vector<int> temp;
    SubSets(vec, n, index, k, temp);
    return vec;
}
int main() {
  int n=3;
  int k=7;
  vector<vector<int>>ans = manager(n,k);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}