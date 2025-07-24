#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return {};
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans;
        int l=0,r=n-1;
        int t=0,b=m-1;
        while (l<=r && t<=b) {
            for (int i=l;i<=r;i++) {
                ans.push_back(grid[t][i]);
            }
            t++;
            for (int i=t;i<=b;i++) {
                ans.push_back(grid[i][r]);
            }
            r--;
            if (t<=b) {
                for (int i = r; i >= l; i--) {
                    ans.push_back(grid[b][i]);
                }
                b--;
            }
            if (l<=r) {
                for (int i=b;i>=t;i--) {
                    ans.push_back(grid[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans=s.spiralOrder(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}