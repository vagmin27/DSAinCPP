#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n, 0), rightMin(n, 0);
        vector<int> leftMax(n, 0), rightMax(n, 0);
        stack<int> minStack;
        stack<int> maxStack;
        // Calculate leftMin and leftMax
        for (int i = 0; i < n; i++) {
            while (!minStack.empty() && nums[minStack.top()] > nums[i])
                minStack.pop();
            leftMin[i] = minStack.empty() ? -1 : minStack.top();
            minStack.push(i);
            while (!maxStack.empty() && nums[maxStack.top()] < nums[i])
                maxStack.pop();
            leftMax[i] = maxStack.empty() ? -1 : maxStack.top();
            maxStack.push(i);
        }
        minStack = stack<int>();
        maxStack = stack<int>();
        // Calculate rightMin and rightMax
        for (int i = n - 1; i >= 0; i--) {
            while (!minStack.empty() && nums[minStack.top()] >= nums[i])
                minStack.pop();
            rightMin[i] = minStack.empty() ? n : minStack.top();
            minStack.push(i);
            while (!maxStack.empty() && nums[maxStack.top()] <= nums[i])
                maxStack.pop();
            rightMax[i] = maxStack.empty() ? n : maxStack.top();
            maxStack.push(i);
        }
        long long sumOfMaxes = 0, sumOfMins = 0;
        for (int i = 0; i < n; i++) {
            sumOfMaxes += (long long)nums[i] * (i - leftMax[i]) * (rightMax[i] - i);
            sumOfMins += (long long)nums[i] * (i - leftMin[i]) * (rightMin[i] - i);
        }
        return sumOfMaxes - sumOfMins;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout << "Sum of subarray ranges: " << sol.subArrayRanges(nums) << endl;
    return 0;
}
