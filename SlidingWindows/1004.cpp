#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int zeroes = 0;
        int maxlen = 0;
        while (r < nums.size()) {
            if (nums[r] == 0) zeroes++;
            while (zeroes > k) {
                if (nums[l] == 0) zeroes--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1};
    int k = 2;

    int result = solution.longestOnes(nums, k);
    cout << "Longest subarray with at most " << k << " zeroes: " << result << endl;

    return 0;
}
