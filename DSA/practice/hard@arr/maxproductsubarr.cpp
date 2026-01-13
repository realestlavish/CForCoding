#include <bits/stdc++.h>
using namespace std;

int maxProductBrute(vector<int> &nums)
{
    int n = nums.size();
    int maxProd = 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int prod = 1;
            for (int k = i; k <= j; k++)
            {
                prod *= nums[k];
            }
            maxProd = max(maxProd, prod);
        }
    }
    return maxProd;
}

int maxProductBetter(vector<int> &nums)
{
    int n = nums.size();
    int maxProd = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int prod = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            prod *= nums[j];
            maxProd = max(maxProd, prod);
        }
    }
    return maxProd;
}
int maxProductOptimal1(vector<int> &nums)
{
    int n = nums.size();
    long long prod1 = 1;
    long long prod2 = 1;
    long long maxProd = 1;
    for (int i = 0; i < n; i++)
    {
        if (prod1 == 0)
            prod1 = 1;
        if (prod2 == 0)
            prod2 = 1;

        prod1 *= nums[i];
        prod2 *= nums[n - i - 1];
        maxProd = max(maxProd, max(prod1, prod2));
    }

    return maxProd;
}

int main()
{
    vector<int> vec = {3, 2, -1, 4, -6, 3, -2, 6};
    cout << "method 1 output: " << maxProductBrute(vec) << endl;
    cout << "method 2 output: " << maxProductBetter(vec) << endl;
    cout << "method 3 output: " << maxProductOptimal1(vec) << endl;
    return 0;
}
