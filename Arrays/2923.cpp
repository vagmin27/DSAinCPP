#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countOnes(vector<int>&v){
        int m=v.size();
        int c=0;
        for(int i=0;i<m;i++){
            if(v[i]==1){
                c++;
            }
        }
        return c;
    } 
    int findChampion(vector<vector<int>>& grid) {
        int n=grid.size();
        int idx=0;
        int mx=0;
        for(int i=0;i<n;i++){
            vector<int>v=grid[i];
            int ans=countOnes(v);
            if(ans>mx){
                mx=ans;
                idx=i;
            }
        }
        return idx;
    }
};
int main(){
    Solution s;
    vector<vector<int>> v={{0,0,1},{1,0,1},{0,0,0}};
    int champ=s.findChampion(v);
    cout<<"The champion row index is: "<<champ<<endl;
}