#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<int>rowCnt(m,0);
        vector<int>colCnt(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j]==1 && (rowCnt[i]>1 || colCnt[j]>1)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    cout << "Number of communicable servers: " << sol.countServers(grid) << endl;
    return 0;
}