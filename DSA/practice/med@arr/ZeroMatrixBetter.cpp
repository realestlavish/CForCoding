#include <bits/stdc++.h>
using namespace std;

void ZeroMatrixBetter(vector<vector<int>> &matrix)
{
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int markrow[n] = {0};
        int markcol[m] = {0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    markrow[i] = 1;
                    markcol[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (markrow[i] == 1 || markcol[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (auto it : matrix)
        {
            for (auto jt : it)
            {
                cout << jt << " ";
            }
            cout << endl;
        }
    }
}

int main()
{

    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    ZeroMatrixBetter(matrix);

    return 0;
}