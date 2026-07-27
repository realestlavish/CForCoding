#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Prime_nums(vector<vector<int>> arr)
{
    if (arr.empty())
        return {};
    
    // Find the maximum value in the queries to determine the sieve range
    int maxi = 0;
    for (auto query : arr)
    {
        maxi = max(maxi, query[1]);
    }

    if (maxi < 2) 
        return vector<int>(arr.size(), 0);

    // Step 1: Use the Sieve of Eratosthenes
    vector<char> is_primee(maxi + 1, 1);
    is_primee[0] = 0;
    is_primee[1] = 0;

    for (int i = 2; i * i <= maxi; i++)
    {
        if (is_primee[i])
        {
            for (int j = i * i; j <= maxi; j += i)
            {
                is_primee[j] = 0;
            }
        }
    }

    // Counting the numbers of prime number till i with prefix sum method
    vector<int> primeCount(maxi + 1, 0);
    for (int i = 1; i <= maxi; ++i)
    {
        primeCount[i] = primeCount[i - 1];
        if (is_primee[i])
        {
            primeCount[i]++;
        }
    }

    // Finding no. of prime numbers in a range from the primeCount vector
    vector<int> res;
    for (auto qu : arr)
    {
        int st = qu[0];
        int end = qu[1];
        if (st == 0)
            res.push_back(primeCount[end]);
        else
            res.push_back(primeCount[end] - primeCount[st - 1]);
    }
    return res;
}

int main()
{
    vector<vector<int>> n = {{1, 7}, {3, 7}};
    vector<int> res = Prime_nums(n);

    for (int x : res)
        cout << x << " ";
}