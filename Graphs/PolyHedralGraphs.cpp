#include <bits/stdc++.h>
using namespace std;
class PolyhedralGraph {
public:
    // Using a pair to represent an edge (vertex1, vertex2)
    using Edge = pair<int, int>;
    PolyhedralGraph() {}
    // Add a vertex to the graph
    void addVertex(int vertex) {
        if (adjacencyList.find(vertex) == adjacencyList.end()) {
            adjacencyList[vertex] = vector<int>();
        }
    }
    // Add an edge to the graph
    void addEdge(int vertex1, int vertex2) {
        addVertex(vertex1);
        addVertex(vertex2);
        adjacencyList[vertex1].push_back(vertex2);
        adjacencyList[vertex2].push_back(vertex1); // Undirected graph
    }
    // Display the graph
    void display() {
        for (const auto& pair : adjacencyList) {
            cout << "Vertex " << pair.first << " is connected to: ";
            for (int neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
private:
    unordered_map<int, vector<int>> adjacencyList;
};
int main() {
    PolyhedralGraph graph;
    // Example: Adding vertices and edges of a tetrahedron
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    // Display the graph
    graph.display();
}