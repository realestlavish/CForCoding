#include <bits/stdc++.h>
using namespace std;

pair<int, int> betterpeakfinder(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++){
        int top=-1,bottom=-1,left=-1,right=-1;
        if(i!=0) top=arr[i-1][j];
        if(i!=(n-1)) bottom=arr[i+1][j];
        if(j!=0) left=arr[i][j-1];
        if(j!=(m-1)) right = arr[i][j+1];
        if(arr[i][j]>top&&arr[i][j]>bottom&&arr[i][j]>left&&arr[i][j]>right) return {i,j};
        }
    }
return {-1, -1};
}

int maxinrowfinder(vector<vector<int>>arr,int n,int m,int col){
    int maxInd=-1,maxRow=-1;
    for (int row = 0; row < n-1; row++)
    {
        if(arr[row][col]>maxInd) maxInd=arr[row][col];maxRow=row;
    }
    return maxRow;
}
pair<int, int> binarypeakfinder(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int low=0;
    int high=m-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        int left=-1;int right=-1;
        int maxinrow=maxinrowfinder(arr,n,m,mid);
        if(mid-1>=0) left=arr[maxinrow][mid-1];
        if(mid+1<m) right=arr[maxinrow][mid+1];
        if(arr[maxinrow][mid]>left&&arr[maxinrow][mid]>right) return{maxinrow,mid};
        else if(arr[maxinrow][mid]>left) low=mid+1;
        else high=mid-1;
    }
    
return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {
        {5, 10, 8}, {4, 25, 7}, {3, 9, 6}};
    pair<int, int> result = betterpeakfinder(mat);
    pair<int, int> result1 = binarypeakfinder(mat);
    cout << "result found: {" << result.first << ", " << result.second << "}" << endl;
    cout << "binary result found: {" << result1.first << ", " << result1.second << "}" << endl;

    return 0;
}