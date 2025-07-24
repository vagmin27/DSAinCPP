#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> nextSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);
        int area = 0;
        for (int i = 0; i < n; i++) {
            int l = heights[i];
            int b;
            if (next[i] == -1) {
                b = n;
            } else {
                b = next[i];
            }
            b = b - prev[i] - 1;
            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }
};
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& height) {
//         int ret = 0;
//         height.push_back(0);
//         vector<int> index;
//         for (int i = 0; i < height.size(); i++) {
//             while (!index.empty() && height[index.back()] >= height[i]) {
//                 int h = height[index.back()];
//                 index.pop_back();
//                 int sidx;
//                 if (index.empty()) {
//                     sidx = -1;
//                 }
//                 else {
//                     sidx = index.back();
//                 }
//                 ret = max(ret, h * (i - sidx - 1));
//             }
//             index.push_back(i);
//         }
//         return ret;
//     }
// };
int main() {
    Solution s;
    int n;
    cout<<"Enter the number of the array: ";
    cin>>n;
    vector<int> heights(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    int result=s.largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << result << endl;
    return 0;
}