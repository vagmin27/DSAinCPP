#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    queue<int>rev(queue<int> q) {
        stack<int> s;
        while(!q.empty()){
            int element=q.front();
            q.pop();
            s.push(element);
        }
        while (!s.empty()) {
            int element=s.top();
            s.pop();
            q.push(element);
        }
        return q;
    }
};

int main() {
    Solution sol;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<"Original queue: ";
    queue<int>temp=q;
    while(!temp.empty()) {
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<endl;
    queue<int>reversedQueue=sol.rev(q);
    cout<<"Reversed queue: ";
    while(!reversedQueue.empty()) {
        cout<<reversedQueue.front()<<" ";
        reversedQueue.pop();
    }
    cout<<endl;
}