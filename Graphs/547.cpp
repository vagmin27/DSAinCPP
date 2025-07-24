#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited(V, 0);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }
};
int main() {
    Solution solution;
    // Test case 1: Example input matrix for connected cities
    vector<vector<int>> isConnected1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    // Test case 2: Another example where all cities are connected
    vector<vector<int>> isConnected2 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    // Test case 3: Another example where cities are isolated
    vector<vector<int>> isConnected3 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    // Output results for each test case
    cout << "Test case 1 result: " << solution.findCircleNum(isConnected1) << endl;
    cout << "Test case 2 result: " << solution.findCircleNum(isConnected2) << endl;
    cout << "Test case 3 result: " << solution.findCircleNum(isConnected3) << endl;
    return 0;
}