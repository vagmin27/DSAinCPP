#include<bits/stdc++.h>
using namespace std;
char maxOccChar(string s){
    int arr[26]={0};
    for(char ch:s){
        if(isalpha(ch)){
            int n=tolower(ch)-'a';
            arr[n]++;
        }
    }
    int mx=-1,ans=-1;
    for(int i=0;i<26;i++){
        if(mx<arr[i]){
            mx=arr[i];
            ans=i;
        }
    }
    return 'a'+ans;
}
int main(){
    string str;
    cout<<"Enter a string: "<<endl;
    getline(cin,str);
    char ch = maxOccChar(str);
    cout<<"The maximum occurring character is: "<<ch<<endl;
}