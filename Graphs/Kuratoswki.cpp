#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isPlanar() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (hasK5Subdivision(i, visited) || hasK3_3Subdivision(i, visited)) {
                    return false; // K5 or K3,3 subdivision found
                }
            }
        }
        return true;
    }
private:
    bool hasK5Subdivision(int u, vector<bool>& visited) {
        visited[u] = true;
        // Collect neighbors
        vector<int> neighbors;
        for (int v : adj[u]) {
            if (!visited[v]) {
                neighbors.push_back(v);
            }
        }
        // Check for K5
        if (neighbors.size() >= 4) {
            for (int i = 0; i < neighbors.size(); ++i) {
                for (int j = i + 1; j < neighbors.size(); ++j) {
                    for (int k = j + 1; k < neighbors.size(); ++k) {
                        for (int l = k + 1; l < neighbors.size(); ++l) {
                            if (areAllConnected(neighbors[i], neighbors[j], neighbors[k], neighbors[l])) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        // Continue DFS
        for (int v : adj[u]) {
            if (!visited[v] && hasK5Subdivision(v, visited)) {
                return true;
            }
        }
        return false;
    }
    bool hasK3_3Subdivision(int u, vector<bool>& visited) {
        visited[u] = true;
       // Collect neighbors
        vector<int> neighbors;
        for (int v : adj[u]) {
            if (!visited[v]) {
                neighbors.push_back(v);
            }
        }
        // // Check for K3,3
        // if (neighbors.size() >= 6) {
        //     for (int i = 0; i < neighbors.size(); ++i) {
        //         for (int j = i + 1; j < neighbors.size(); ++j) {
        //             for (int k = j + 1; k < neighbors.size(); ++k) {
        //                 if (areAllConnected(neighbors[i], neighbors[j],neighbors[k])) {
        //                     unordered_set<int> otherPart;
        //                     for (int l = 0; l < neighbors.size(); ++l) {
        //                         if (l != i && l != j && l != k) {
        //                             otherPart.insert(neighbors[l]);
        //                         }
        //                     }
        //                     if (otherPart.size() >= 3 && allConnectedTo(neighbors[i], otherPart) &&allConnectedTo(neighbors[j], otherPart) &&allConnectedTo(neighbors[k], otherPart)) {
        //                         return true;
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        // Continue DFS
        for (int v : adj[u]) {
            if (!visited[v] && hasK3_3Subdivision(v, visited)) {
                return true;
            }
        }
        return false;
    }
    bool areAllConnected(int a, int b, int c, int d) {
        return isConnected(a, b) && isConnected(a, c) && isConnected(a, d) && isConnected(b, c) && isConnected(b, d) && isConnected(c, d);
    }
    bool isConnected(int a, int b) {
        return find(adj[a].begin(), adj[a].end(), b) != adj[a].end();
    }
    bool allConnectedTo(int node, unordered_set<int>& otherPart) {
        for (int neighbor : otherPart) {
            if (!isConnected(node, neighbor)) {
                return false;
            }
        }
        return true;
    }
};
// class Graph {
// public:
//     int V; // Number of vertices
//     vector<vector<int>> adj; // Adjacency list
//     Graph(int V) {
//         this->V = V;
//         adj.resize(V);
//     }
//     void addEdge(int u, int v) {
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     bool hasK5Subdivision(int u, vector<int>& visited) {
//         visited[u] = 1;
//         // Collect neighbors
//         vector<int> neighbors;
//         for (int v : adj[u]) {
//             if (!visited[v]) {
//                 neighbors.push_back(v);
//             }
//         }
//         // If there are 5 or more neighbors, we can check combinations
//         if (neighbors.size() >= 4) {
//             // Check combinations of neighbors to see if they form K5
//             for (int i = 0; i < neighbors.size(); ++i) {
//                 for (int j = i + 1; j < neighbors.size(); ++j) {
//                     for (int k = j + 1; k < neighbors.size(); ++k) {
//                         for (int l = k + 1; l < neighbors.size(); ++l) {
//                             if (areAllConnected(neighbors[i], neighbors[j], neighbors[k], neighbors[l])) {
//                                 return true;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         // Reset visited for the next DFS
//         visited[u] = 0;
//         for (int v : adj[u]) {
//             if (!visited[v] && hasK5Subdivision(v, visited)) {
//                 return true;
//             }
//         }
//         return false;
//     }
//     bool hasK3_3Subdivision(int u, vector<int>& visited) {
//         visited[u] = 1;
//         // Collect neighbors
//         vector<int> neighbors;
//         for (int v : adj[u]) {
//             if (!visited[v]) {
//                 neighbors.push_back(v);
//             }
//         }
//         // If there are 6 or more neighbors, we can check for K3,3
//         if (neighbors.size() >= 6) {
//             // Check for bipartiteness and if they form K3,3
//             for (int i = 0; i < neighbors.size(); ++i) {
//                 for (int j = i + 1; j < neighbors.size(); ++j) {
//                     for (int k = j + 1; k < neighbors.size(); ++k) {
//                         if (areAllConnected(neighbors[i], neighbors[j], neighbors[k])) {
//                             // Check for the other part of K3,3
//                             unordered_set<int> otherPart;
//                             for (int l = 0; l < neighbors.size(); ++l) {
//                                 if (l != i && l != j && l != k) {
//                                     otherPart.insert(neighbors[l]);
//                                 }
//                             }
//                             if (otherPart.size() >= 3 && allConnectedTo(neighbors[i], otherPart) &&
//                                 allConnectedTo(neighbors[j], otherPart) &&
//                                 allConnectedTo(neighbors[k], otherPart)) {
//                                 return true;
//                             }
//                         }
//                     }
//                 }
//             }
//         }

//         // Reset visited for the next DFS
//         visited[u] = 0;
//         for(int v : adj[u]){
//             if(!visited[v] && hasK3_3Subdivision(v, visited)){
//                 return true;
//             }
//         }
//         return false;
//     }
//     bool areAllConnected(int a, int b, int c, int d) {
//         return (isConnected(a, b) && isConnected(a, c) && isConnected(a, d) &&
//                 isConnected(b, c) && isConnected(b, d) && isConnected(c, d));
//     }
//     bool isConnected(int a, int b) {
//         return find(adj[a].begin(), adj[a].end(), b) != adj[a].end();
//     }
//     bool allConnectedTo(int node, unordered_set<int>& otherPart) {
//         for (int neighbor : otherPart) {
//             if (!isConnected(node, neighbor)) {
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool isPlanar() {
//         vector<int> visited(V, 0);
//         for (int i = 0; i < V; ++i) {
//             if (visited[i] == 0) {
//                 if (hasK5Subdivision(i, visited) || hasK3_3Subdivision(i, visited)) {
//                     return false; // K5 or K3,3 subdivision found
//                 }
//             }
//         }
//         return true;
//     }
// };
int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(0, 5);
    if (g.isPlanar()) {
        cout << "The graph is planar." << endl;
    }
    else {
        cout << "The graph is not planar." << endl;
    }
}