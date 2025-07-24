#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string reverseWords(string s){
    int n = s.size();
        reverse(s.begin(),s.end());
        int i=0;
        int l=0,r=0;
        while(i<n){
            while(i<n && s[i]!=' '){
                s[r++]=s[i++];
            }
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r]=' ';
                r++;
                l=r;
            }
        i++;
        }
    s = s.substr(0,r-1);
    return s;
}
int main(){
    string s="Hello World this is Vagmin";
    cout<<"Reversed Words: "<<reverseWords(s)<<endl;
}