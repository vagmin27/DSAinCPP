#include <iostream>
#include <vector>
using namespace std;

// Leetcode Problem 46: Permutations
class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int i) {
        if (i >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            solve(nums, ans, i + 1);
            swap(nums[i], nums[j]); // Backtrack
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, ans, 0);
        return ans;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> result = solution.permute(nums);
    cout << "Permutations:\n";
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}