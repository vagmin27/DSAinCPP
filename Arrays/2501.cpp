#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        int out = 0;

        for (auto &n : nums) {
            int t = sqrt(n);
            if (t * t == n) {
                out = max(out, m[n] = m[t] + 1);
            } else {
                m[n] = 1;
            }
        }

        return out > 1 ? out : -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 4, 9, 16, 25, 36, 49, 64};
    int result = sol.longestSquareStreak(nums);
    cout << "Longest Square Streak: " << result << endl;
    return 0;
}
