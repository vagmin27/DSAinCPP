#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    void solve(vector<int>&nums,int n, int k, vector<int> c, vector<vector<int>>& ans){
        if(k == 0){
            ans.push_back(c);
            return;
        }
        for(int i=n;i<=nums.size()-k;i++){
            c.push_back(nums[i]);
            solve(nums,i+1,k-1,c,ans);
            c.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i=0;i<n;i++){
            nums.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> c;
        solve(nums,0,k,c,ans);
        return ans;
    }
};
int main() {
    Solution solution;
    int n,k;
    cout << "Enter the numbers: ";
    cin>>n>>k;
    vector<vector<int>> result = solution.combine(n,k);
    cout << "Permutations:\n";
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}