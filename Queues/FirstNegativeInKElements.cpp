#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> printFirstNegativeInteger(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq;
        vector<int> ans;
        // Process the first window of size k
        for (int i = 0; i < k; i++) {
            if (arr[i] < 0) {
                dq.push_back(i);
            }
        }
        // Store answer for the first k-sized window
        if (!dq.empty()) {
            ans.push_back(arr[dq.front()]);
        }
        else {
            ans.push_back(0);
        }
        // Process remaining windows
        for (int i = k; i < n; i++) {
            // Removal of elements outside the current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            // Addition of the new element
            if (arr[i] < 0) {
                dq.push_back(i);
            }
            // Answer storing
            if (!dq.empty()) {
                ans.push_back(arr[dq.front()]);
            }
            else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {1, -2, 3, -4, 5};
    int k = 2;
    vector<int> result = sol.printFirstNegativeInteger(arr, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}