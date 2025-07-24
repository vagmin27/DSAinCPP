#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r=matrix.size();
    int c=matrix[0].size();
    int row=0;
    int col=c-1;
    while(row<r && col>=0){
        int e=matrix[row][col];
        if(e==target) return true;
        if(e<target) row++;
        else col--;
    }
    return false;
}
int main(){
    vector<vector<int>>v={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    searchMatrix(v,target);
}