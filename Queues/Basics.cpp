#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int>q;
    q.push(11);
    cout<<"Front of queue is: "<<q.front()<<endl;
    cout<<"Back of queue is: "<<q.back()<<endl;
    q.push(15);
    cout<<"Front of queue is: "<<q.front()<<endl;
    cout<<"Back of queue is: "<<q.back()<<endl;
    q.push(13);
    cout<<"Front of queue is: "<<q.front()<<endl;
    cout<<"Back of queue is: "<<q.back()<<endl;
    cout<<"size of queue is: "<<q.size()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<"size of queue is: "<<q.size()<<endl;
    if(q.empty()){
        cout<<"Queue is empty. "<<endl;
    }
    else{
        cout<<"Queue is not empty. "<<endl;
    }
}