#include<bits/stdc++.h>
using namespace std;
vector<int> wavePrint(vector<vector<int>> arr, int n, int m) {
    vector<int> ans;
    for (int j=0;j<m;j++) {
        if (j & 1) {
            for (int i=n-1;i>=0;i--) {
                ans.push_back(arr[i][j]);
            }
        } else {
            for (int i = 0; i < n; i++) {
                ans.push_back(arr[i][j]);
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(m));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin>>v[i][j];
        }
    }
    vector<int>ans=wavePrint(v,n,m);
    for (int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}