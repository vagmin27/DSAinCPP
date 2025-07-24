#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
    }
}
int main() {
    // Graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},      // Node 0 is connected to Node 1 and 2
        {0, 3, 4},   // Node 1 is connected to Node 0, 3, and 4
        {0},         // Node 2 is connected to Node 0
        {1},         // Node 3 is connected to Node 1
        {1}          // Node 4 is connected to Node 1
    };
    vector<bool> visited(graph.size(), false);
    cout << "DFS starting from node 0: ";
    dfs(0, visited, graph);
    cout << endl;
    return 0;
}