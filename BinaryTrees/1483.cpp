#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> P;
    TreeAncestor(int n, vector<int>& parent) {
        P.resize(20, vector<int>(parent.size(), -1));
        for (int i = 0; i < parent.size(); i++) {
            P[0][i] = parent[i];
        }
        for (int i = 1; i < 20; i++) {
            for (int node = 0; node < parent.size(); node++) {
                int nodep = P[i - 1][node];
                if (nodep != -1) P[i][node] = P[i - 1][nodep];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; i++) {
            if (k & (1 << i)) {
                node = P[i][node];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};
int main() {
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
    TreeAncestor treeAncestor(7, parent);
    cout << "Ancestor of node 5 at distance 2: " << treeAncestor.getKthAncestor(5, 2) << endl; // Expected: 0
    cout << "Ancestor of node 6 at distance 3: " << treeAncestor.getKthAncestor(6, 3) << endl; // Expected: -1
    cout << "Ancestor of node 3 at distance 1: " << treeAncestor.getKthAncestor(3, 1) << endl; // Expected: 1
    cout << "Ancestor of node 5 at distance 1: " << treeAncestor.getKthAncestor(5, 1) << endl; // Expected: 1
    return 0;
}