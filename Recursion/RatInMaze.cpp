#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool isSafe(int x, int y, int n, vector<vector<int>>& v, vector<vector<int>>& mat) {
        if(x >= 0 && x < n && y >= 0 && y < n && v[x][y] == 0 && mat[x][y] == 1){
            return true;
        }
        else return false;
    }
    void solve(vector<vector<int>>& mat, int n, vector<string>& ans, int x, int y, vector<vector<int>>& v, string& path) {
        if (x == n-1 && y == n-1) {
            ans.push_back(path);
            return;
        }
        v[x][y] = 1; // Mark cell as visited
        // Move down
        if (isSafe(x+1,y,n,v,mat)) {
            path.push_back('D');
            solve(mat,n,ans,x+1,y,v,path);
            path.pop_back();
        }
        // Move left
        if (isSafe(x,y-1,n,v,mat)) {
            path.push_back('L');
            solve(mat,n,ans,x,y-1,v,path);
            path.pop_back();
        }
        // Move right
        if (isSafe(x,y+1,n,v,mat)) {
            path.push_back('R');
            solve(mat,n,ans,x,y+1,v,path);
            path.pop_back();
        }
        // Move up
        if (isSafe(x-1,y,n,v,mat)) {
            path.push_back('U');
            solve(mat,n,ans,x-1,y,v,path);
            path.pop_back();
        }
        v[x][y] = 0; // Backtrack: unmark cell
    }

public:
    vector<string> findPath(vector<vector<int>>& mat) {
        vector<string> ans;
        int n = mat.size();
        if (mat[0][0]==0 || mat[n-1][n-1]==0) return ans; // Check for blocked start/end
        vector<vector<int>> v(n,vector<int>(n,0)); // Visited matrix
        string path = "";
        solve(mat,n,ans,0,0,v,path);
        sort(ans.begin(), ans.end()); // Sort paths
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> result = sol.findPath(mat);
    for (const string& path : result) {
        cout << path << endl;
    }
    return 0;
}