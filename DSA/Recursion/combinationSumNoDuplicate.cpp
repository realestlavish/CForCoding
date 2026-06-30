#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> combinationSum2(const vector<int> &arr, int index,
                                    int currentSum, int k) {
  sort(arr.begin(), arr.end());
  vector<int> vec;
  vector<vector<int>> res;
  for (int i = index; i < arr.size(); i++) {
    if (i > index && arr[i] == arr[i - 1])
      continue;
    if (k == 0) {
      res.push_back(vec);
    }
    if (arr[index] > k)
      break;

    vec.push_back(arr[index]);
    combinationSum2(arr, index + 1, currentSum, k - arr[index]);
    vec.pop_back();
  }
}
vector<vector<int>> combi(vector<int> &candidates, int target) {
  sort(candidates.begin(),
       candidates.end());  // Sort the candidates to handle duplicates
  vector<vector<int>> res; // To store the final answer
  vector<int> ds;          // To store the current combination
  combinationSum2(candidates, 0, 0, target); // Call the helper function
  return res;                                // Return all valid combinations
}

int main() {
  vector<int> arr = {2, 3, 6, 7};
  int k = 7;
  combi(arr, k);
  return 0;
}
