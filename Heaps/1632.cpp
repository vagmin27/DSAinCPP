#include<bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent;
    int find(int i) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
public:
    DSU(int size) {
        parent.resize(size);
        for (int i = 0; i < size; i++) parent[i] = i;
    }
    void unite(int i, int j) {
        int pi = find(i);
        int pj = find(j);
        if (pi != pj) parent[pj] = pi;
    }
    int getParent(int i) {
        return find(i);
    }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> result(n, vector<int>(m, 0));
        vector<int> rowRank(n, 0), colRank(m, 0);
        // Priority queue to process elements in ascending order
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pq.push({matrix[i][j], i * m + j});
            }
        }
        while (!pq.empty()) {
            vector<int> indices;
            int currentValue = pq.top().first;
            // Collect all elements with the same value
            while (!pq.empty() && pq.top().first == currentValue) {
                indices.push_back(pq.top().second);
                pq.pop();
            }
            // Union-Find to group elements in the same row/column
            DSU dsu(indices.size());
            vector<int> rowGroup(n, -1), colGroup(m, -1);
            for (int idx = 0; idx < indices.size(); idx++) {
                int r = indices[idx] / m, c = indices[idx] % m;
                if (rowGroup[r] != -1) dsu.unite(idx, rowGroup[r]);
                rowGroup[r] = idx;
                if (colGroup[c] != -1) dsu.unite(idx, colGroup[c]);
                colGroup[c] = idx;
            }
            // Assign ranks to groups
            unordered_map<int, int> groupRanks;
            for (int idx = 0; idx < indices.size(); idx++) {
                int group = dsu.getParent(idx);
                int r = indices[idx] / m, c = indices[idx] % m;
                groupRanks[group] = max(groupRanks[group], max(rowRank[r], colRank[c]) + 1);
            }
            // Update ranks and results
            for (int idx = 0; idx < indices.size(); idx++) {
                int r = indices[idx] / m, c = indices[idx] % m;
                int group = dsu.getParent(idx);
                result[r][c] = groupRanks[group];
                rowRank[r] = colRank[c] = groupRanks[group];
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    // Example test case
    vector<vector<int>> matrix = {
        {1, 2, 2},
        {2, 3, 3},
        {3, 3, 4}
    };
    // Get the transformed matrix with ranks
    vector<vector<int>> result = sol.matrixRankTransform(matrix);
    // Print the result
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}