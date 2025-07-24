#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1;
        int ans = n;
        vector<int> a(n), b(n), v;
        // Compute LIS from the left
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            auto idx = lower_bound(begin(v), end(v), x);
            a[i] = idx - begin(v);
            if (idx != end(v)) *idx = x;
            else v.push_back(x);
        }
        v.clear();
        // Compute LIS from the right
        for (int i = n - 1; i >= 0; i--) {
            int x = nums[i];
            auto it = lower_bound(begin(v), end(v), x);
            b[i] = it - begin(v);
            if (it != end(v)) *it = x;
            else v.push_back(x);
        }
        // Calculate minimum removals
        for (int i = 1; i < n - 1; i++) {
            if (a[i] && b[i])
                ans = min(ans, (n - (a[i] + b[i] + 1)));
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {2, 1, 1, 5, 6, 2, 3, 1};
    int result = solution.minimumMountainRemovals(nums);
    if (result != -1) {
        cout << "Minimum removals to form a mountain array: " << result << endl;
    }
    else {
        cout << "Not possible to form a mountain array." << endl;
    }
    return 0;
}
//The space complexity is O(n) due to the storage of the arrays a, b, and the vector v.
// The complexity of each lower_bound operation is O(logk), where k is the current length of the subsequence being built.
// In the worst case, this can be O(n) since the length of the subsequence can grow to the size of n.
// Therefore, both the LIS computations take O(nlogn).
// The final loop that checks for potential peaks runs in O(n).
// Overall, the time complexity is O(nlogn).