#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int val=*max_element(nums.begin(), nums.end());
        int a=0; // Length of longest subarray found
        int c=0; // Current length of subarray with max element
        for (int i=0;i<n;i++) {
            if(nums[i]==val){
                c++;
            }
            else{
                a=max(c,a);
                c=0;
            }
        }
        return max(a,c);
    }
};
int main() {
    Solution s;
    vector<int>nums;
    cout<<"Enter the number of elements in the array: ";
    int n;
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for (int i=0;i<n;i++) {
        int num;
        cin>>num;
        nums.push_back(num);
    }
    int res=s.longestSubarray(nums);
    cout<<"Length of the longest subarray containing the maximum element: "<<res<<endl;
    return 0;
}