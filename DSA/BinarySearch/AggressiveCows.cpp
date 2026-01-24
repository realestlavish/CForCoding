#include <bits/stdc++.h>
using namespace std;

bool cowplacer(vector<int> &vec, int distance, int n, int k)
{
    int placedcows = 1;
    int lastposition = vec[0];
    for (int i = 1; i <= n; i++)
    {
        if (vec[i] - lastposition >= distance)
        {
            placedcows++;
            lastposition = vec[i];
        }
    }
    if (placedcows >= k)
    {
        return true;
    }
    else
        return false;
}
int aggressivecowsbasic(vector<int> &vec, int k, int n)
{
    sort(vec.begin(), vec.end());
    int difference = vec[n - 1] - vec[0];
    for (int i = 1; i <= difference; i++)
    {
        if (cowplacer(vec, i, n, k) == true)
        {
            continue;
        }
        else
        {
            return i - 1;
        }
    }
    return -1;
}

int aggressivecowsbinarysearch(vector<int> &vec, int k, int n)
{
    sort(vec.begin(), vec.end());
    int difference = vec[n - 1] - vec[0];
    int low = 1, high = difference;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (cowplacer(vec, mid, n, k) == true)
        {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}

int main()
{
    vector<int> vec = {0, 3, 4, 7, 10, 9};
    int k = 5;
    int n = vec.size();

    // Call the function
    int result = aggressivecowsbinarysearch(vec, k, n);
    cout << "Result: " << result << endl;

    return 0;
}
