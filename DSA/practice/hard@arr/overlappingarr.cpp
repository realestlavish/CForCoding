#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bruteoverlappingarr(vector<vector<int>>& arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    for(int i=0; i<n; i++){
        int start = arr[i][0];
        int end = arr[i][1];
        
        // Skip if current interval is already merged in previous iterations
        if (!result.empty() && start <= result.back()[1]) {
            continue;
        }
        
        // Merge all overlapping intervals starting from i
        for(int j=i+1; j<n; j++){
            if (arr[j][0] <= end) {
                end = max(arr[j][1], end);
            }
            else{
                break;
            }
        }
        result.push_back({start, end});
    }
    return result;
}
                                                        

vector<vector<int>> optimaloverlappingarr(vector<vector<int>>& arr){
    int n = arr.size();
    vector<vector<int>> result;
    for(int i=0; i<n; i++){
        if (result.empty() || arr[i][0]>arr.back()[1]) {
            result.push_back(arr[i]);
        }
        else{
            arr.back()[1] = max(arr.back()[1],arr[i][1]);
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = bruteoverlappingarr(arr);
    for(auto interval : result){
        cout << interval[0] << " " << interval[1] << " ";
    }
    return 0;
}