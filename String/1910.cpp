#include<iostream>
#include<algorithm>
using namespace std;
string removeOccurrences(string s,string part){
    while(s.length()!=0 && s.find(part)<s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
}
int main(){
    string s,part;
    cout<<"Enter string: ";
    cin>>s;
    cout<<"Enter part: ";
    cin>>part;
    cout<<"String after removing: "<<part<<" becomes : "<<removeOccurrences(s,part)<<endl;
}