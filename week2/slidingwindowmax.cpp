#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // stores indices
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove out-of-window elements from front
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove smaller elements from back
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i); // add current index

        // Add to result if window is at least size k
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);
    
    for (int val : res)
        cout << val << " ";
    return 0;
}
