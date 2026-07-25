#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> divisors(int n)
{
    vector<int> divisorsVec;

    for (int div = 1; div * div <= n; div++)
    {
        if (n % div == 0)
        {
            divisorsVec.push_back(div);
            if(div!=(n/div)) divisorsVec.push_back(n / div);
        }
    }
    sort(divisorsVec.begin(), divisorsVec.end());
    return divisorsVec;
}

int main()
{
    int n = 12;

    vector<int> res = divisors(n);

    for (int x : res)
        cout << x << " ";
}