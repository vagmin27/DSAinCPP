#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node, vector<int> adjList[], vector<int>& visited) {
        visited[node] = 1;
        for (auto it : adjList[node]) {
            if (!visited[it]) {
                dfs(it, adjList, visited);
            }
        }
    }

  public:
    int numProvinces(vector<vector<int>>& adj, int V) {
        vector<int> adjList[V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        vector<int> visited(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i, adjList, visited);
            }
        }
        return cnt;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> adj = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    int V = adj.size();
    cout << "Number of Provinces: " << obj.numProvinces(adj, V) << endl;
    return 0;
}

