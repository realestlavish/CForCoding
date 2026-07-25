#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> PrimeFactors(int n)
{
    vector<int> primeSet;

    for (int div = 2; div*div <= n; div++)
    {
        if (n % div == 0)
        {
            primeSet.insert(div);
            while (n % div == 0)
            {
                n /= div;
            }
        }
    }

    if (n > 1)
        primeSet.insert(n);

    return primeSet;
}

int main()
{
    int n = 780;

    vector<int> res = PrimeFactors(n);

    for (int x : res)
        cout << x << " ";
}