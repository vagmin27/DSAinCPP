#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        // Initialize BFS with all the cells that are 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        // Perform BFS
        while (!q.empty()) {
            auto top = q.front();
            int x = top.first;
            int y = top.second;
            q.pop();
            // Explore the four possible directions
            for (auto& dir : direction) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                // Check if the new position is within bounds and hasn't been visited
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && dist[newX][newY] == -1) {
                    dist[newX][newY] = dist[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
        return dist;
    }
};
int main() {
    Solution obj;
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };
    vector<vector<int>> result = obj.updateMatrix(mat);
    for (auto row : result) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}