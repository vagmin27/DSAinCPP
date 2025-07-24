#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
    // Initialize an adjacency list
    vector<vector<int>> adj(V);
    // Populate the adjacency list with edges
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        // Add the undirected edges
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}
// Function to print the adjacency list
void printAdjacencyList(int V, vector<vector<int>>& adj) {
    for(int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": ";
        for(int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    // Define the number of vertices and edges
    int V = 4;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    // Build the graph using printGraph function
    vector<vector<int>> adj = printGraph(V, edges);
    // Print the adjacency list
    printAdjacencyList(V, adj);
    return 0;
}