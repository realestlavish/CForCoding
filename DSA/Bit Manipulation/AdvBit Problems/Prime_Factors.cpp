#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> PrimeFactors(int n)
{
    unordered_set<int> primeSet;

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

    unordered_set<int> res = PrimeFactors(n);

    for (int x : res)
        cout << x << " ";
}

int main()
{
    int n = 65;
    unordered_set<int> res = PrimeFactors(n);
    for (int num : res)
    {
        cout << num << " ";
    }
}