#include <stack>
#include <vector>
#include <iostream>
using namespace std;

vector<int> bruteCelebrity(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> know_me(n, 0);
    vector<int> i_know(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                i_know[i]++;
                know_me[j]++;
            }
        }
    }
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (i_know[i] == 0 && know_me[i] == n - 1)
        {
            result.push_back(i);
        }
    }
    return result;
}

vector<int> optimalCelebrity(vector<vector<int>> graph)
{
    int n = graph.size();
    int top = 0, down = n - 1;
    while (top < down)
    {
        if (graph[top][down] == 1)
        {
            top++;
        }
        else if (graph[down][top] == 1)
        {
            down--;
        }
        else
        {
            top++;
            down--;
        }
    }
    if (top > down)
        return vector<int>{-1};
    if (top == down)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != top && (graph[top][i] == 1 || graph[i][top] == 0))
            {
                return vector<int>{-1};
            }
        }
        return vector<int>{top};
    }
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0}};

    vector<int> brute_result = bruteCelebrity(graph);
    vector<int> result = optimalCelebrity(graph);

    cout << "Brute Force Result: ";
    for (int x : brute_result)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << "Optimal Result: ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}