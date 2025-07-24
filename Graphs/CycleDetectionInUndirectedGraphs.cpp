#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to perform DFS and detect cycle
    bool isCyclicDFS(int node, vector<int>& visited, vector<vector<int>>& adj) {
        visited[node] = 1;  // Mark the current node as visited
        for (auto neighbour : adj[node]) {
            // If the neighbor hasn't been visited, recursively call DFS
            if (!visited[neighbour]) {
                if (isCyclicDFS(neighbour, visited, adj)) {
                    return true;  // Cycle detected
                }
            }
            // If the neighbor is visited and not the parent, a cycle is found
            else {
                return true;  // Cycle detected
            }
        }
        return false;  // No cycle detected in this path
    }
    // Function to check if the graph contains a cycle
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visited(n, 0);  // Track visited nodes
        // Perform DFS for each unvisited node
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (isCyclicDFS(i, visited, adj)) {
                    return true;  // Cycle detected
                }
            }
        }
        return false;  // No cycle detected in the graph
    }
};

int main() {
    Solution solution;
    // Test case: A graph with a cycle
    vector<vector<int>> adj1 = {
        {1},        // Node 0 connects to node 1
        {0, 2},     // Node 1 connects to node 0 and 2
        {1, 3},     // Node 2 connects to node 1 and 3
        {2, 4},     // Node 3 connects to node 2 and 4
        {3}         // Node 4 connects to node 3 (form a cycle here)
    };
    // Check if the graph contains a cycle
    if (solution.isCycle(adj1)) {
        cout << "Graph has a cycle!" << endl;
    }
    else {
        cout << "Graph does not have a cycle!" << endl;
    }
    // Test case: A graph without a cycle
    vector<vector<int>> adj2 = {
        {1},        // Node 0 connects to node 1
        {0, 2},     // Node 1 connects to node 0 and 2
        {1, 3},     // Node 2 connects to node 1 and 3
        {2}         // Node 3 connects to node 2 (no cycle)
    };
    // Check if the graph contains a cycle
    if (solution.isCycle(adj2)) {
        cout << "Graph has a cycle!" << endl;
    }
    else {
        cout << "Graph does not have a cycle!" << endl;
    }
    return 0;
}