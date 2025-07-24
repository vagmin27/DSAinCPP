#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        // Create a max-heap
        priority_queue<int> pq;
        // Build a heap of the first 'k' elements
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }
        // Traverse the rest of the array
        for (int i = k; i < arr.size(); i++) {
            if (arr[i] < pq.top()) {
                pq.pop(); // Remove the largest element
                pq.push(arr[i]); // Add the current element
            }
        }
        // The root of the heap is the kth smallest element
        return pq.top();
    }
};
int main() {
    Solution solution;
    vector<int> arr = {12, 3, 5, 7, 19, 2};
    int k = 4;
    cout << "The " << k << "th smallest element is: " << solution.kthSmallest(arr, k) << endl;
    return 0;
}