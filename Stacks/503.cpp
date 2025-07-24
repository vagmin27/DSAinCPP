#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n, -1);
        stack<int> s;
        // Iterate over the array twice to handle the circular nature
        for (int i=0;i<2*n;i++) {
            while (!s.empty() && arr[s.top()] < arr[i % n]) {
                ans[s.top()]=arr[i % n];
                s.pop();
            }
            if(i<n){ // Only push the indices of the first pass
                s.push(i);
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>v=s.nextGreaterElements(arr);
    for (int num:v) {
        cout<<num<<" ";
    }
    return 0;
}