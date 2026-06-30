#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

void combinationSum(const vector<int> &arr, int index, int k, vector<int> &vec,
                    vector<vector<int>> &res) {
  if (index == arr.size()) {
    if (k == 0) {
      res.push_back(vec);
    }
    return;
  }

  if (arr[index] <= k) {
    vec.push_back(arr[index]);
    combinationSum(arr, index, k - arr[index], vec, res);
    vec.pop_back();
  }

  combinationSum(arr, index + 1, k, vec, res);
}

vector<vector<int>> combination(const vector<int> &arr, int target) {
  vector<vector<int>> res;                  // To store the final answer
  vector<int> vec;                          // To store the current combination
  combinationSum(arr, 0, target, vec, res); // Call the helper function
  return res;                               // Return all valid combinations
}
int main() {
  vector<int> arr = {2, 3, 6, 7};
  int k = 7;
  vector<vector<int>>r= combination(arr, k);
  for(auto it:r){
    for(auto i:it){
      cout<<i<<" ";
    }
    cout<<endl;
  }
  return 0;
}
