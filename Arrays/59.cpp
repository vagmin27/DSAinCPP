#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int c = 1;
        for (int i= 0; i< (n + 1) / 2; i++) {
            for (int j=i;j<n-i;j++) {
                result[i][j]=c++;
            }
            for (int j=i+1;j<n-i;j++) {
                result[j][n-i-1]=c++;
            }
            for (int j=n-i-2;j>=i;j--) {
                result[n-i-1][j]=c++;
            }
            for (int j= n-i-2;j>i;j--) {
                result[j][i]=c++;
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    vector<vector<int>>grid=s.generateMatrix(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}