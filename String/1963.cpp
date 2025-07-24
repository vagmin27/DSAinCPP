#include<bits/stdc++.h>
using namespace std;
int minSwaps(string s) {
    int n=s.size()-1;
    int swaps=0;
    int b=0;
    for(int i=0;i<n;i++){
        b=s[i]=='[' ? b+1 : b-1;
        if(b<0){
            while(s[n]==']') n--;
            swap(s[i],s[n]);
            swaps++;
            b=1; 
        }
    }
    return swaps;
}
int main(){
    string s;
    cin>>s;
    cout<<minSwaps(s)<<endl;
}