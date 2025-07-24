#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int r=matrix.size();
        int c=matrix[0].size();
        int s=0;
        int e=(r*c)-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int midVal= matrix[mid/c][mid%c];
            if(midVal==target){
                return true;
            }
            else if(midVal<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    int target=7;
    cout<<s.searchMatrix(v,target)<<endl;
}