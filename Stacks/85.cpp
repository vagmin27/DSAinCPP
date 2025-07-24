#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int ret = 0;
        vector<int> index;
        for (int i = 0; i < height.size(); i++) {
            while (!index.empty() && height[index.back()] >= height[i]) {
                int h = height[index.back()];
                index.pop_back();
                int sidx = index.empty() ? -1 : index.back();
                ret = max(ret, h * (i - sidx - 1));
            }
            index.push_back(i);
        }
        height.pop_back();
        return ret;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                }
                else {
                    heights[j] = 0;
                }
            }
            area = max(area, largestRectangleArea(heights));
        }
        return area;
    }
};
// class Solution {
// private:
//     vector<int> nextSmallerElement(vector<int>& arr, int n) {
//         stack<int> s;
//         s.push(-1);
//         vector<int> ans(n);
//         for (int i = n - 1; i >= 0; i--) {
//             int curr = arr[i];
//             while (s.top() != -1 && arr[s.top()] >= curr) {
//                 s.pop();
//             }
//             ans[i] = s.top();
//             s.push(i);
//         }
//         return ans;
//     }
//     vector<int> prevSmallerElement(vector<int>& arr, int n) {
//         stack<int> s;
//         s.push(-1);
//         vector<int> ans(n);
//         for (int i = 0; i < n; i++) {
//             int curr = arr[i];
//             while (s.top() != -1 && arr[s.top()] >= curr) {
//                 s.pop();
//             }
//             ans[i] = s.top();
//             s.push(i);
//         }
//         return ans;
//     }
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> next = nextSmallerElement(heights, n);
//         vector<int> prev = prevSmallerElement(heights, n);
//         int area = 0;
//         for (int i = 0; i < n; i++) {
//             int l = heights[i];
//             int b;
//             if (next[i] == -1) {
//                 b = n;
//             } else {
//                 b = next[i];
//             }
//             b = b - prev[i] - 1;
//             int newArea = l * b;
//             area = max(area, newArea);
//         }
//         return area;
//     }
// public:
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         if (matrix.empty() || matrix[0].empty())
//             return 0;
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<int> heights(m, 0);
//         int area = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == '1') {
//                     heights[j] += 1;
//                 }
//                 else {
//                     heights[j] = 0;
//                 }
//             }
//             area = max(area, largestRectangleArea(heights));
//         }
//         return area;
//     }
// };
int main() {
    Solution sol;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << "Maximal Rectangle Area: " << sol.maximalRectangle(matrix) << endl;
    return 0;
}