#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        int n = nums2.size();
        for (int i = n - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }
            if (st.empty()) {
                mp[num] = -1;
            } else {
                mp[num] = st.top();
            }
            st.push(num);
        }
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = solution.nextGreaterElement(nums1, nums2);
    cout << "Next greater elements: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}