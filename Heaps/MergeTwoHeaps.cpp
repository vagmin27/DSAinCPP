#include<bits/stdc++.h>
using namespace std;
class Solution {
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;  // Initialize largest as root
        int left = 2 * i + 1;  // Left child index (0-indexed)
        int right = 2 * i + 2; // Right child index (0-indexed)
        // If left child is larger than root
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        // If right child is larger than root or left child
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        // If largest is not root, swap and continue heapifying
        if (largest != i) {
            swap(arr[i], arr[largest]);  // Swap root with largest child
            heapify(arr, n, largest);    // Recursively heapify the affected sub-tree
        }
    }
public:
    vector<int> mergeHeaps(vector<int>& a, vector<int>& b, int n, int m) {
        // Merge Both Arrays into One
        vector<int> ans;
        for (auto i : a) ans.push_back(i);
        for (auto i : b) ans.push_back(i);
        // Build Heap using merged array
        int size = ans.size();
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(ans, size, i);
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> a = {10, 5, 3, 2, 4};
    vector<int> b = {9, 7, 6};
    vector<int> result = sol.mergeHeaps(a, b, a.size(), b.size());
    // Output the merged heap
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}