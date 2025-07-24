#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rowMovement = {0, 0, 1, -1};
    vector<int> colMovement = {1, -1, 0, 0};

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<tuple<int, int, int>> s;
        s.insert({0, 0, 0});
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;
        while (!s.empty()) {
            auto [cost, row, col] = *(s.begin());
            s.erase(s.begin());
            if (row == n - 1 && col == m - 1) {
                return cost;
            }
            int p = grid[row][col];
            for (int i = 1; i <= 4; i++) {
                int newRow = row + rowMovement[i - 1];
                int newCol = col + colMovement[i - 1];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    int newCost = cost + (p != i);
                    if (newCost < dis[newRow][newCol]) {
                        dis[newRow][newCol] = newCost;
                        s.insert({newCost, newRow, newCol});
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