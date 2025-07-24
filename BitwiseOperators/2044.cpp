#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int,int>m;
    int mx=-1;
    void subsets(vector<int>& nums,int val,int pos){
        if(nums.size()==pos){
            if(mx<val) mx=val;
            m[val]++;
            return;
        }
        subsets(nums,val,pos+1);
        val=val|nums[pos];
        subsets(nums,val,pos+1);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        subsets(nums,0,0);
        return m[mx];
    }
};
int main(){
    Solution s;
    vector<int> nums={3,1};
    cout<<s.countMaxOrSubsets(nums);
}