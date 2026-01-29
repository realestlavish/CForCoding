#include <bits/stdc++.h>
using namespace std;
// T.C= K*(n-1)+n;
//  Function to minimize the maximum distance after placing k gas stations
long double bruteminimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howManyplaced(n - 1, 0); // howManyplaced[i]: extra stations between arr[i] and arr[i+1]

    // Place k gas stations one at a time
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        long double maxSection = -1;
        int maxInd = -1;

        // Find the segment with the current largest section length
        for (int i = 0; i < n - 1; i++)
        {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (howManyplaced[i] + 1.0);

            if (sectionLength > maxSection)
            {
                maxSection = sectionLength;
                maxInd = i;
            }
        }

        // Add a gas station in the largest segment
        howManyplaced[maxInd]++;
    }

    // Find the final maximum distance after placing all gas stations
    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++)
    {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength = diff / (howManyplaced[i] + 1.0);
        maxAns = max(maxAns, sectionLength);
    }

    return maxAns;
}

// T-C= (n-1logn+klogn), S-C = (N-1)
long double betterminimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howManyplaced(n - 1, 0); // howManyplaced[i]: extra stations between arr[i] and arr[i+1]
    priority_queue<pair<long double, int>> pq;
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }
    for (int i = 1; i <= k; i++)
    {
        auto topper = pq.top();
        pq.pop();
        auto IndSec = topper.second;
        howManyplaced[IndSec]++;
        long double diff = arr[IndSec + 1] - arr[IndSec];
        long double SectionL = diff / (long double)(howManyplaced[IndSec] + 1);
        pq.push({SectionL, IndSec});
    }
    return pq.top().first;
}

int gasstationnumbers(vector<int> &arr, long double mid)
{
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int numberofstations =( arr[i] - arr[i - 1]) / mid;
        if ((arr[i] - arr[i - 1]) / mid ==( numberofstations * mid)) numberofstations--;
        cnt += numberofstations;
    }
    return cnt;
}
long double binaryminimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    long double low = 0;
    long double high = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        high = max(high, (long double)arr[i] - arr[i - 1]);
    }

    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low + high) / 2.0;

        if (gasstationnumbers(arr, mid) > k)
            low = mid;
        else
            high = mid;
    }
    return high;
}

int main()
{
    vector<int> arr = {1, 13, 17, 23};
    int k = 5;

    long double ans1 = bruteminimiseMaxDistance(arr, k);
    cout << "Brute Force Answer: " << ans1 << "\n";

    long double ans2 = betterminimiseMaxDistance(arr, k);
    cout << "Better Approach Answer: " << ans2 << "\n";

    long double ans3 = binaryminimiseMaxDistance(arr, k);
    cout << "Binary Search Answer: " << ans3 << "\n";

    return 0;
}
