#include <bits/stdc++.h>
using namespace std;

int hourcounter(vector<int> &arr, int speed)
{
    int totalhours = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        totalhours += ceil((double)arr[j] / speed);
    }
    return totalhours;
}
int kokobasic(vector<int> &arr, int n, int target)
{
    sort(arr.begin(), arr.end());
    int h = arr[n - 1];
    long long sum = 0;
    vector<int> res;

    for (int i = 1; i <= h; i++)
    {
        int sum = hourcounter(arr, i);
        if (sum <= target)
            return i;
    }

    return -1;
}
// low & highh will end up at opposite polarity, LOW was not possible answer at first but it becomes possible later in answerr, so reverse polarity. ans will be at LOW.
int binarykoko(vector<int> &arr, int n, int target)
{
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long sum = 0;
        for (int j = 0; j < n; j++)
            if (hourcounter(arr, mid) <= target)
            {
                ans = mid;
                high = mid - 1;
            }
        low = mid + 1;
    }
    return ans;
}

int main()
{
    int N = 5;
    vector<int> arr = {25, 12, 8, 14, 19};
    int target = 5;
    int result = kokobasic(arr, N, target);
    if (result == -1)
    {
        cout << "No solution found" << endl;
    }
    else
    {
        cout << "Minimum eating speed: " << result << endl;
    }
    return 0;
}