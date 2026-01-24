#include <bits/stdc++.h>
using namespace std;

int booksplacer(vector<int> &vec, int allocatedpages, int n)
{
    int placedbooks = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + vec[i] > allocatedpages)
        {
            placedbooks++;
            sum = vec[i];
        }
        else
            sum += vec[i];
    }
    return placedbooks;
}
int booksbasic(vector<int> &vec, int students, int n)
{
    if (students > n)
        return -1;
    int max = *max_element(vec.begin(), vec.end());
    int sum = accumulate(vec.begin(), vec.end(), 0);
    for (int i = 111; i <= sum; i++)
    {
        if (booksplacer(vec, i, n) == students)
            return i;
    }
    return -1;
}

int booksbinarysearch(vector<int> &vec, int students, int n)
{
    int low = 1, high = accumulate(vec.begin(), vec.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (booksplacer(vec, mid, n) > students)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    vector<int> vec = {25, 46, 28, 49, 24};
    int books = 4;
    int n = vec.size();

    // Call the function
    int result = booksbinarysearch(vec, books, n);
    cout << "Result: " << result << endl;

    return 0;
}
