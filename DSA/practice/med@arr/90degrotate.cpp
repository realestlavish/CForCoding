#include <bits/stdc++.h>
using namespace std;

void rotater(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (i != j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main()
{

    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {19, 10, 11, 12}, {13, 14, 15, 16}};
    rotater(matrix);

    return 0;
}