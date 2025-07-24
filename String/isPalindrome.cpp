#include<bits/stdc++.h>
using namespace std;
char toLowerCase(char ch){
    if((ch>='a'&& ch<='z')||(ch>='0'&& ch<='9')){
        return ch;
    }
    else if(ch>='A'&& ch<='Z'){
        return ch+'a'-'A';
    }
}
bool checkPalindrome(const string& str){
    int n=str.length();
    int s=0,e=n-1;
    while(s<=e){
        if(toLowerCase(str[s]!=toLowerCase(str[e]))){
            return false;
        }
        else{
            s++;
            e--;
        }
    }
    return true;
}
int main(){
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    if(checkPalindrome(str)){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not palindrome"<<endl;
    }
}