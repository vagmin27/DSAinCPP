#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        bool firstRowZero=false;
        bool firstColZero=false;
        for (int j=0;j<c;j++) {
            if (matrix[0][j]==0) {
                firstRowZero=true;
                break;
            }
        }
        for (int i=0;i<r;i++) {
            if (matrix[i][0]==0) {
                firstColZero=true;
                break;
            }
        }
        for (int i=1;i<r;i++) {
            for (int j=1;j<c;j++) {
                if (matrix[i][j]==0) {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for (int i=1;i<r;i++) {
            for (int j=1;j<c;j++) {
                if (matrix[i][0]==0 || matrix[0][j]==0) {
                    matrix[i][j]=0;
                }
            }
        }
        if(firstRowZero){
            for(int j=0;j<c;j++) {
                matrix[0][j]=0;
            }
        }
        if(firstColZero){
            for(int i=0;i<r;i++) {
                matrix[i][0]=0;
            }
        }
    }
};
int main(){
    Solution s;
    vector<vector<int>> v={{1,1,1},{1,0,1},{1,1,1}};
    s.setZeroes(v);
    int r=v.size();
    int c=v[0].size();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}