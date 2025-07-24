#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
// void RotateArray(vector<int>&nums, int k){
//     int n=nums.size();
//     k=k%n;
//     reverse(nums.begin(),nums.end());
//     reverse(nums.begin(),nums.begin()+k);
//     reverse(nums.begin()+k,nums.end());
//     for(int i=0;i<n;i++){
//         cout<<nums[i]<<" ";
//     }
// }
void RotateArray(vector<int>&nums, int k){
    int n=nums.size();
    vector<int> v(n);
    for(int i=0;i<n;i++){
        v[(i+k)%n]=nums[i];
    }
    nums=v;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}
int main(){
    vector<int>nums={1,2,3,4,5,6,7};
    int k=3;
    RotateArray(nums,k);
}