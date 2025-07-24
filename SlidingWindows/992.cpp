#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int help(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int ans = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            mpp[nums[r]]++;
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums, k) - help(nums, k - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    int result = sol.subarraysWithKDistinct(nums, k);
    cout << "Number of subarrays with exactly " << k << " distinct integers: " << result << endl;

    return 0;
}
