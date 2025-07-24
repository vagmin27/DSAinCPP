#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(const vector<vector<int>>& vec, int vertices, int edges, int source) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (const auto& edge : vec) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // For undirected graph
    }
    // Initialize distance vector
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    // Set to track the minimum distance nodes
    set<pair<int, int>> s;
    s.insert({0, source});
    while (!s.empty()) {
        auto top = *s.begin();
        int d = top.first;
        int topNode = top.second;
        s.erase(s.begin()); // Remove the node from the set
        // Traverse neighbors
        for (const auto& neighbor : adj[topNode]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            if (d + weight < dist[nextNode]) {
                // If a shorter path is found, update the distance
                auto rec = s.find({dist[nextNode], nextNode});
                if (rec != s.end()) {
                    s.erase(rec); // Remove old record
                }
                dist[nextNode] = d + weight; // Update distance
                s.insert({dist[nextNode], nextNode}); // Add new record
            }
        }
    }
    return dist;
}
int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;
    vector<vector<int>> vec(edges, vector<int>(3));
    cout << "Enter edges (u, v, w):" << endl;
    for (int i = 0; i < edges; ++i) {
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2]; // Read edges
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    vector<int> distances = dijkstra(vec, vertices, edges, source);
    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < vertices; ++i) {
        if (distances[i] == INT_MAX) {
            cout << "Vertex " << i << ": Infinity\n";
        } else {
            cout << "Vertex " << i << ": " << distances[i] << "\n";
        }
    }
    return 0;
}