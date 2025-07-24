#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;
        // Count fresh oranges and add rotten ones to the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        // If there are no fresh oranges, return 0
        if (freshOranges == 0) return 0;
        int time = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // BFS to spread the rotting effect
        while (!q.empty()) {
            int size = q.size();
            bool rotSpread = false;
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : directions) {
                    int newX = x + dx;
                    int newY = y + dy;
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                        grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;  // Make the orange rotten
                        freshOranges--;
                        q.push({newX, newY});
                        rotSpread = true;
                    }
                }
            }
            if (rotSpread) time++;
        }
        // Check if there are any fresh oranges left
        return (freshOranges == 0) ? time : -1;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    int result = obj.orangesRotting(grid);
    cout << "Minimum time to rot all oranges: " << result << endl;
    return 0;
}