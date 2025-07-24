#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int countSubstr(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int n = nums.size();
        int l = 0;
        long long sum = 0;
        int cnt = 0;
        for (int r = 0; r < n; ++r) {
            sum += (nums[r] % 2);
            while (sum > goal) {
                sum -= (nums[l] % 2);
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countSubstr(nums, k) - countSubstr(nums, k - 1);
    }
};

int main() {
    Solution solution;

    // Test case
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    int result = solution.numberOfSubarrays(nums, k);
    cout << "Number of subarrays with exactly " << k << " odd numbers: " << result << endl;

    return 0;
}
