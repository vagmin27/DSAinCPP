#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> s;
    s.push(1);
    cout<<"Printing elements: "<<s.top()<<endl;
    s.push(2);
    cout<<"Printing elements: "<<s.top()<<endl;
    s.push(3);
    cout<<"Printing elements: "<<s.top()<<endl;
    s.push(4);
    cout<<"Printing elements: "<<s.top()<<endl;
    s.pop();
    cout<<"Printing elements: "<<s.top()<<endl;
    s.pop();
    cout<<"Printing elements: "<<s.top()<<endl;
    s.pop();
    cout<<"Printing elements: "<<s.top()<<endl;
    if(s.empty()){
        cout<<"Stack is empty "<<endl;
    }
    else{
        cout<<"Stack is not empty "<<endl;
    }
    cout<<"Size of sack is: "s.size()<<endl;
}