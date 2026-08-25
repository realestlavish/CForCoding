#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    vector<int> result;
    deque<int> dq; // Will store INDICES of the array elements
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        // 1. Remove the index at the front if it is no longer inside the window [i - k + 1, i]
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        // 2. Maintain monotonic decreasing order: 
        // Remove indices from the back whose values are smaller than the current element's value.
        // (They are useless because the current element is larger AND will stay in the window longer)
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        
        // 3. Push the current index into the deque
        dq.push_back(i);
        
        // 4. Once we have processed at least 'k' elements, start recording the maximums.
        // The maximum for the current window is always at the front of the deque.
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    
    return result;
}