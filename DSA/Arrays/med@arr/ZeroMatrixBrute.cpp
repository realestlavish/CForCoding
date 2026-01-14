#include <bits/stdc++.h>
using namespace std;

void zerorow(vector<vector<int>> &matrix, int row)
{
    int m = matrix[0].size();
    for (int j = 0; j < m; j++)
    {
        if (matrix[row][j] != 0)
        {
            matrix[row][j] = -1;
        }
    }
}

void zerocol(vector<vector<int>> &matrix, int col)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][col] != 0)
        {
            matrix[i][col] = -1;
        }
    }
}

void ZeroMatrix(vector<vector<int>> &matrix)
{
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zerorow(matrix, i); // m
                    zerocol(matrix, j); // n
                }
            }
        }

        for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] == -1)
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
    ZeroMatrix(matrix);

    return 0;
}