#include<iostream>
using namespace std;
void reverse(int i,int j,string& str){
    if(i>j) return;
    swap(str[i],str[j]);
    i++;
    j--;
    reverse(i,j,str);
}
int main(){
    string str;
    cout<<"Enter the string :"<<str<<endl;
    cin>>str;
    reverse(0,str.length()-1,str);
    cout<<"Reversed String is: "<<str<<endl;
}