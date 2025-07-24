#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int countSubstrings(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int n = nums.size();
        int l = 0;
        long long sum = 0;
        int cnt = 0;
        for (int r = 0; r < n; ++r) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubstrings(nums, goal) - countSubstrings(nums, goal - 1);
    }
};

int main() {
    Solution solution;

    // Test case
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    int result = solution.numSubarraysWithSum(nums, goal);
    cout << "Number of subarrays with sum = " << goal << ": " << result << endl;

    return 0;
}
