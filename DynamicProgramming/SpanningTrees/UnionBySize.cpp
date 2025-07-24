#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank;
    vector<int>parent;
    vector<int>size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n=1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void UnionBySize(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_u] = size[ulp_v];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_v] = size[ulp_u];
        }
    }
};

int main() {
    int n = 5; // Number of nodes
    DisjointSet ds(n);
    // Perform Union operations
    ds.UnionBySize(1, 2);
    ds.UnionBySize(2, 3);
    ds.UnionBySize(4, 5);
    ds.UnionBySize(6, 7);
    ds.UnionBySize(5, 6);
    ds.UnionBySize(3, 7);
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