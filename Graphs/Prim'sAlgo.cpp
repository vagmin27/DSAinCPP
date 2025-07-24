#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> Edge; // (weight, vertex)

class Graph {
public:
    int V; // Number of vertices
    vector<vector<Edge>> adj; // Adjacency list

    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int w) {
        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); // For undirected graph
    }

    void primMST() {
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);
        
        key[0] = 0; // Start from the first vertex

        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, inMST);
            inMST[u] = true;

            for (const auto& edge : adj[u]) {
                int weight = edge.first;
                int v = edge.second;

                if (!inMST[v] && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }

        printMST(parent,key);
    }

private:
    int minKey(vector<int>& key, vector<bool>& inMST) {
        int min = INT_MAX, min_index;

        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void printMST(vector<int>& parent,vector<int> &key){
        cout << "Edge \tWeight\n";
        for (int i = 1; i < V; i++)
            cout << parent[i] << " - " << i << "\t" << key[i] <<endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primMST();

    return 0;
}
