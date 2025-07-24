#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int lmax = 0;
        int rmax = 0;
        int total = 0;
        int l = 0;
        int r = n - 1;
        while (l < r) {
            if (height[l] <= height[r]) {
                if (lmax > height[l]) {
                    total += lmax - height[l];
                }
                else {
                    lmax = height[l];
                }
                l++;
            }
            else {
                if (rmax > height[r]) {
                    total += rmax - height[r];
                }
                else {
                    rmax = height[r];
                }
                r--;
            }
        }
        return total;
    }
};
int main() {
    Solution solution;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1}; // Example input
    int result = solution.trap(height);
    cout << "Trapped rainwater: " << result << endl; // Output should be 6
    return 0;
}