#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> count;
        int n = nums.size();
        // Calculate the number of 1's in the binary representation of each number
        for (auto it : nums) {
            int tmp = 0;
            while (it > 0) {
                if (it & 1) tmp++;
                it = (it >> 1);
            }
            count.push_back(tmp);
        }
        int prev_max = INT_MIN;  // Use INT_MIN for better readability
        for (int i = 0; i < n;) {
            int start = i;
            int end = i;
            int curr_max = INT_MIN, curr_min = INT_MAX;
            // Group elements with the same number of 1's in their binary representation
            for (int j = i; j < n; j++) {
                if (count[j] == count[i]) {
                    curr_max = max(curr_max, nums[j]);
                    curr_min = min(curr_min, nums[j]);
                    end = j + 1;
                } else {
                    break;
                }
            }
            // Check if the current group can maintain the overall sorted order
            if (curr_min < prev_max) return false;
            prev_max = curr_max;
            // Move to the next group
            i = end;
        }
        return true;
    }
};
int main() {
    Solution solution;
    // Test case 1
    vector<int> nums1 = {1, 3, 2, 4};
    cout << "Test case 1: " << (solution.canSortArray(nums1) ? "Yes" : "No") << endl;
    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Test case 2: " << (solution.canSortArray(nums2) ? "Yes" : "No") << endl;
    // Test case 3
    vector<int> nums3 = {4, 2, 1, 3};
    cout << "Test case 3: " << (solution.canSortArray(nums3) ? "Yes" : "No") << endl;
    return 0;
}