#include<bits/stdc++.h>
using namespace std;
bool checkInclusion(string s1, string s2) {
    int n=s1.length();
    int m=s2.length();
    vector<int> str1(26,0),str2(26,0);
    for(char c:s1){
        str1[c-'a']++;
    }
    for(int i=0;i<m;i++){
        str2[s2[i]-'a']++;
        if(i>=n){
            str2[s2[i-n]-'a']--;
        }
        if(str2==str1) return true;
    }
    return false;
}
int main(){
    string s1="ab",s2="eidbaooo";
    cout<<checkInclusion(s1,s2)<<endl;
}