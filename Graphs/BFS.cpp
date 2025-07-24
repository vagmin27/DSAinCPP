#include <bits/stdc++.h>
using namespace std;
void bfs(int start, const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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

    cout << "BFS starting from node 0: ";
    bfs(0, graph);
    cout << endl;

    return 0;
}