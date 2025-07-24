#include<bits/stdc++.h>
using namespace std;
vector<int> findArraySun(vector<int>&a,int n,vector<int>&b,int m){
    int i=n-1;
    int j=m-1;
    vector<int>v;
    int carry=0;
    while(i>=0 && j>=0){
        int sum=a[i]+b[j]+carry;
        carry=sum/10;
        v.push_back(sum%10);
        i--;
        j--;
    }
    while(i>=0){
        int sum=a[i]+carry;
        carry=sum/10;
        v.push_back(sum%10);
        i--;
    }
    while(j>=0){
        int sum=b[j]+carry;
        carry=sum/10;
        v.push_back(sum%10);
        j--;
    }
    while(carry!=0){
        int sum=carry;
        carry=sum/10;
        v.push_back(sum%10);
    }
    reverse(v.begin(),v.end());
    return v;
}
int main(){
    vector<int> a={1,2,3};
    vector<int> b={4,5,6};
    int n=a.size();
    int m=b.size();
    vector<int> v=findArraySun(a,n,b,m);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}