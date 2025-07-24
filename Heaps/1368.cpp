#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rowMovement = {0, 0, 1, -1};
    vector<int> colMovement = {1, -1, 0, 0};
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // Priority queue to store (cost, row, col), with the smallest cost at the top
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});
        // Distance matrix to track minimum cost to reach each cell
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;
        while (!pq.empty()) {
            auto [cost, row, col] = pq.top();
            pq.pop();
            // If we reached the bottom-right corner, return the cost
            if (row == n - 1 && col == m - 1) {
                return cost;
            }
            // If this cost is not better than the stored one, skip processing
            if (cost > dis[row][col]) continue;
            // Current grid direction
            int p = grid[row][col];
            // Explore all 4 possible directions
            for (int i = 0; i < 4; i++) {
                int newRow = row + rowMovement[i];
                int newCol = col + colMovement[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    // Calculate new cost
                    int newCost = cost + (p != (i + 1));
                    if (newCost < dis[newRow][newCol]) {
                        dis[newRow][newCol] = newCost;
                        pq.push({newCost, newRow, newCol});
                    }
                }
            }
        }
        return 0;
    }
};
int main() {
    Solution solution;
    // Example test case
    vector<vector<int>> grid = {
        {1, 1, 3},
        {3, 2, 2},
        {1, 1, 4}
    };
    int result = solution.minCost(grid);
    cout << "Minimum cost to reach the bottom-right corner: " << result << endl;
    return 0;
}