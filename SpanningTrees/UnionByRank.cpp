#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank;
    vector<int>parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void UnionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main() {
    int n = 5; // Number of nodes
    DisjointSet ds(n);

    // Perform Union operations
    ds.UnionByRank(1, 2);
    ds.UnionByRank(2, 3);
    ds.UnionByRank(4, 5);

    // Check if two nodes are in the same set
    if(ds.findParent(1) == ds.findParent(3)) {
        cout << "1 and 3 are in the same set." << endl;
    } else {
        cout << "1 and 3 are in different sets." << endl;
    }

    if(ds.findParent(1) == ds.findParent(5)) {
        cout << "1 and 5 are in the same set." << endl;
    } else {
        cout << "1 and 5 are in different sets." << endl;
    }

    return 0;
}