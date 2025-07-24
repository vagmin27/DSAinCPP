#include<bits/stdc++.h>
using namespace std;
string removeDuplicates(string s) {
    int n=s.length();
    string str;
    for(int i=0;i<n;i++){
        if(!str.empty() && str.back()==s[i]){
            str.pop_back();
        }
        else{
            str.push_back(s[i]);
        }
    }
    return str;
}
int main(){
    string s;
    cout<<"Enter a string : ";
    cin>>s;
    cout<<"String after removing all adjacent duplicates: "<<removeDuplicates(s)<<endl;
}