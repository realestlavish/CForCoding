#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;



vector<int> SubSets(vector<int> arr,vector<int> vec,int sum,int index,int n){
    if(index>=n){
        vec.push_back(sum);
    }
    
    SubSets(arr,vec,sum+arr[index],index+1,n);
    SubSets(arr,vec,sum,index+1,n);
   
}



vector<int> manager(vector<int> arr){
    vector<int> vec;
    int sum=0;
    int n=arr.size();
    int index=0;
    return SubSets(arr, vec, sum, index,n);
}
int main() {
  vector<int> arr = {2, 3, 6};
  vector<int>ans = manager(arr);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}