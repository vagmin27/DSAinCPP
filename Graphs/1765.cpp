#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        // Initialize water cells and set their height to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    q.emplace(i, j);
                    ans[i][j] = 0;
                }
            }
        }
        // Perform BFS
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto& [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                // Skip invalid or already visited cells
                if (x < 0 || x >= m || y < 0 || y >= n || ans[x][y] != -1) 
                    continue;
                // Assign height and add to queue
                ans[x][y] = ans[i][j] + 1;
                q.emplace(x, y);
            }
        }
        return ans;
    }
};
int main() {
    Solution obj;
    vector<vector<int>> isWater = {
        {0, 1},
        {0, 0}
    };
    vector<vector<int>> result = obj.highestPeak(isWater);
    // Print result
    for (const auto& row : result) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}