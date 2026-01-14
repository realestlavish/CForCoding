#include <bits/stdc++.h>
using namespace std;

// To find a number in Pascal's Triangle

int Pascalnumber(int n, int r)
{
    int res = 1;
    for (int i = 1; i <= r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// To find a row in Pascal's Triangle
vector<int> PascalRow(int row)
{
    vector<int> rest;
    int res = 1;
    rest.push_back(res);
    for (int col = 1; col < row; col++)
    {
        res = res * (row - col);
        res = res / col;
        rest.push_back(res);
    }
    return rest;
}

void PascalTriangle(int row)
{
    vector<vector<int>> triangle;
    int anty;
    for (int i = 1; i <= row; i++)
    {
        triangle.push_back(PascalRow(i));
    }
    for (auto ms : triangle)
    {
        for (auto m : ms)
        {
            cout << m << endl;
        }
    }
}

int main()
{
    int row;
    cin >> row;
    PascalTriangle(row);
    return 0;
}