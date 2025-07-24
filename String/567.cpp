#include<bits/stdc++.h>
using namespace std;
bool checkEqual(int a[26], int b[26]){
    for(int i=0;i<26;i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}
bool checkInclusion(string s1, string s2) {
    int n=s1.length();
    int m=s2.length();
    int count1[26]={0};
    for(int i=0;i<n;i++){
        int idx=s1[i]-'a';
        count1[idx]++;
    }
    int i=0;
    int w=s1.length();
    int count2[26]={0};
    while(i<w && i<s2.length()){
        int idx=s2[i]-'a';
        count2[idx]++;
        if(checkEqual(count1,count2)){
            return true;
        }
        while(i<s2.length()){
            char newChar = s2[i];
            int idx=newChar - 'a';
            count2[idx]++;
            char oldChar = s2[i-w];
            idx=oldChar-'a';
            count2[idx]--;
            i++;
            if(checkEqual(count1,count2))
            return true;
        }
    }
}
int main(){
    string s1="ab",s2="eidbaooo";
    cout<<checkInclusion(s1,s2)<<endl;
}