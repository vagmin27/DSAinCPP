#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;
    
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        moveToS2IfNeeded();
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        moveToS2IfNeeded();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    void moveToS2IfNeeded() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
};

int main() {
    MyQueue queue;
    // Test pushing elements
    queue.push(1);
    queue.push(2);
    queue.push(3);
    cout << "Peek: " << queue.peek() << endl; // Should output 1
    cout << "Pop: " << queue.pop() << endl;   // Should output 1
    cout << "Peek: " << queue.peek() << endl; // Should output 2
    cout << "Pop: " << queue.pop() << endl;   // Should output 2
    cout << "Is empty: " << queue.empty() << endl; // Should output 0 (false)
    cout << "Pop: " << queue.pop() << endl;   // Should output 3
    cout << "Is empty: " << queue.empty() << endl; // Should output 1 (true)
    return 0;
}