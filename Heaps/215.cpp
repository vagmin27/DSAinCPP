#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // Min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> pq;
        // Add the first k elements to the priority queue
        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }
        // Process the remaining elements
        for (int i = k; i < n; i++) {
            if (nums[i] > pq.top()) {
                pq.pop(); // Remove the smallest element in the heap
                pq.push(nums[i]); // Add the current element
            }
        }
        // The top of the priority queue is the kth largest element
        return pq.top();
    }
};
int main() {
    Solution solution;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    // Find the kth largest element
    int result = solution.findKthLargest(nums, k);
    // Output the result
    cout << "The " << k << "th largest element is: " << result << endl;
    return 0;
}