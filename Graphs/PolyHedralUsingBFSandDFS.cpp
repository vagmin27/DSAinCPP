#include <bits/stdc++.h>
using namespace std;
class PolyhedralGraph {
public:
    using Edge = pair<int, int>;
    void addVertex(int vertex) {
        if (adjacencyList.find(vertex) == adjacencyList.end()) {
            adjacencyList[vertex] = vector<int>();
        }
    }
    void addEdge(int vertex1, int vertex2) {
        addVertex(vertex1);
        addVertex(vertex2);
        adjacencyList[vertex1].push_back(vertex2);
        adjacencyList[vertex2].push_back(vertex1); // Undirected graph
    }
    void bfs(int start) {
        unordered_map<int, bool> visited;
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";
            for (int neighbor : adjacencyList[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
    void dfs(int start) {
        unordered_map<int, bool> visited;
        stack<int> s;
        s.push(start);
        cout << "DFS Traversal: ";
        while (!s.empty()) {
            int vertex = s.top();
            s.pop();
            if (!visited[vertex]) {
                visited[vertex] = true;
                cout << vertex << " ";
                // Push neighbors onto the stack in reverse order to maintain order
                for (auto it = adjacencyList[vertex].rbegin(); it != adjacencyList[vertex].rend(); ++it) {
                    if (!visited[*it]) {
                        s.push(*it);
                    }
                }
            }
        }
        cout << endl;
    }
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
    // Example: Adding vertices and edges
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 6);
    graph.addEdge(5, 6);
    // Display the graph
    graph.display();
    // Perform BFS and DFS
    graph.bfs(1);
    graph.dfs(1);
    return 0;
}