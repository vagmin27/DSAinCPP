#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function for DFS traversal
    void dfs(int u, vector<int>& discovery, vector<int>& low, vector<int>& parent,
        vector<bool>& visited, vector<bool>& articulation, vector<int> adj[]) {
        
        static int time = 0;  // Static variable to track discovery time
        visited[u] = true;
        discovery[u] = low[u] = ++time;
        int children = 0;  // Count of children in DFS tree

        // Explore all adjacent vertices
        for (int v : adj[u]) {
            if (!visited[v]) {
                parent[v] = u;
                children++;

                // Recursive DFS call
                dfs(v, discovery, low, parent, visited, articulation, adj);

                // After the DFS call, check if the subtree rooted at v has a connection back to an ancestor of u
                low[u] = min(low[u], low[v]);

                // Articulation point conditions
                if ((parent[u] == -1 && children > 1) ||  // Root with more than one child
                    (parent[u] != -1 && low[v] >= discovery[u])) {
                    articulation[u] = true;
                }
            } else if (v != parent[u]) {
                // Update low[u] for back edge
                low[u] = min(low[u], discovery[v]);
            }
        }
    }

    // Function to find all articulation points
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> discovery(V, -1), low(V, -1), parent(V, -1);
        vector<bool> visited(V, false), articulation(V, false);

        // Perform DFS for each unvisited vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, discovery, low, parent, visited, articulation, adj);
            }
        }

        // Collect all articulation points
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (articulation[i]) {
                result.push_back(i);
            }
        }

        // If no articulation point exists, return [-1]
        if (result.empty()) {
            result.push_back(-1);
        }
        
        return result;
    }
};

int main() {
    // Example test case
    Solution sol;
    
    int V = 5;
    vector<int> adj[V];
    
    // Creating a graph:  
    // 0-1-2
    // | |
    // 3 4
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[0].push_back(3);
    adj[3].push_back(0);
    adj[1].push_back(4);
    adj[4].push_back(1);
    
    vector<int> articulation_points = sol.articulationPoints(V, adj);
    
    // Print articulation points
    for(int point : articulation_points) {
        cout << point << " ";
    }
    return 0;
}
