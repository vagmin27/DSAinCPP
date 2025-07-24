#include<iostream>
using namespace std;
int NthStair(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    int ans=NthStair(n-1)+NthStair(n-2);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the base stair :";
    cin>>n;
    int ways=NthStair(n);
    cout<<"Number of ways to reach the "<<n<<"th stair : "<<ways<<endl;
}