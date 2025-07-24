#include<bits/stdc++.h>
using namespace std;
int minLength(string s) {
    bool found;
    do {
        found=false;
        size_t pos;
        while((pos=s.find("AB"))!=string::npos) {
            s.erase(pos,2);
            found=true;
        }
        while((pos=s.find("CD"))!=string::npos) {
            s.erase(pos,2);
            found=true;
        }
    }
    while(found);
    return s.length();
}
// using stacks
// class Solution {
// public:
//     int minLength(string s) {
//         stack<char> st;
//         int n=s.size();
//         for(int i=0;i<n;i++){
//     if(!st.empty()&&((st.top()=='A' && s[i]=='B')||(st.top()=='C' && s[i]=='D'))){
//                 st.pop();
//             }else{
//                 st.push(s[i]);
//             }
//         }
//         return st.size();
//     }
// };
int main(){
    string s;
    cout<<"Enter a string : ";
    cin>>s;
    cout<<"Minimum string length after removing substrings is : "<<minLength(s)<<endl;
}