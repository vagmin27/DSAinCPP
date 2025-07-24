#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long mx=0;
        int s=0;
        int e=skill.size()-1;
        long sum=skill[s]+skill[e];
        while(s<=e){
            long curr=skill[s]+skill[e];
            if(sum!=curr) return -1;
            mx=mx+(skill[s]*skill[e]);
            s++;
            e--;
        }
        return mx;
    }
};
int main(){
    Solution s;
    vector<int> v={3,2,5,1,3,4};
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    cout<<s.dividePlayers(v)<<endl;
}