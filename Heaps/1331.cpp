#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        // Priority queue to store {value, index}, sorted by value
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({arr[i], i});
        }
        int rank = 1;
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            ans[top.second] = rank;
            // Update rank only if the next value is different
            if (!pq.empty() && pq.top().first != top.first) {
                rank++;
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> arr = {40, 10, 20, 20, 30};
    // Call the function and get the result
    vector<int> result = solution.arrayRankTransform(arr);
    // Display the result
    cout << "Input array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\nRanked array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}