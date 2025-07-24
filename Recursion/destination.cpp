#include<iostream>
using namespace std;
void Destination(int s,int d){
    cout<<s<<" "<<d<<endl;
    if(s==d) {
        cout<<"Reached"<<endl;
        return;
    }
    s++;
    Destination(s,d);
}
int main(){
    int s,d;
    cin>>s>>d;
    cout<<endl;
    Destination(s,d);
    // cout<<a<<endl;
}