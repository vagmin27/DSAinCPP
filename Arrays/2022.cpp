#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    int s = original.size();
    if (m * n != s) {
        return {};
    }      
    vector<vector<int>> v(m, vector<int>(n));
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < n; k++) {
            v[j][k] = original[j * n + k];
        }
    }
    return v;
}
int main(){
    vector<int> v={1,2,3,4};
    int m=2,n=2;
    vector<vector<int>> grid=construct2DArray(v,m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}