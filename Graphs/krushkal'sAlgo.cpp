#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, weight;
};
class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    void unionSets(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            }
            else if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            }
            else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
};
class Graph {
public:
    int V, E;
    vector<Edge> edges;
    Graph(int V, int E) : V(V), E(E) {}
    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }
    void kruskalMST() {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });
        DisjointSet ds(V);
        vector<Edge> mst;
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            if (ds.find(u) != ds.find(v)) {
                ds.unionSets(u, v);
                mst.push_back(edge);
            }
        }
        printMST(mst);
    }
private:
    void printMST(const vector<Edge>& mst) {
        cout << "Edge \tWeight\n";
        for (const auto& edge : mst) {
            cout << edge.u << " - " << edge.v << "\t" << edge.weight << " \n";
        }
    }
};
int main() {
    Graph g(5, 7);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);
    g.kruskalMST();
    return 0;
}