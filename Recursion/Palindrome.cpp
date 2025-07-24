#include<iostream>
using namespace std;
bool Palindrome(string& str, int i,int j){
    if(i>j) return true;
    if(str[i]!=str[j]) return false;
    else return Palindrome(str,i+1,j-1);
}
int main(){
    string str;
    cin>>str;
    bool isPalindrome=Palindrome(str,0,str.length()-1);
    if(isPalindrome){
        cout<<"The given string is a Palindrome "<<endl;
    }
    else{
        cout<<"The given string is not a Palindrome "<<endl;
    }
}