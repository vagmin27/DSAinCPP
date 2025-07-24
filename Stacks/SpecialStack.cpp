#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<int> s;
    int mini;
public:
    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        }
        else {
            if (data < mini) {
                s.push(2 * data - mini);
                mini = data; // Update mini to the new minimum
            } else {
                s.push(data);
            }
        }
    }
    
    void pop() {
        if (s.empty()) {
            return; // Stack is empty, nothing to pop
        }
        int curr = s.top();
        s.pop();
        if (curr < mini) {
            mini = 2 * mini - curr; // Update mini
        }
    }
    
    int top() {
        if (s.empty()) {
            return -1; // Stack is empty
        }
        int curr = s.top();
        if(curr<mini){ // Return the correct top value
            return mini;
        }
        else{
            return curr;
        }
    }
    
    bool isEmpty() {
        return s.empty(); // Check if stack is empty
    }
    int getMin() {
        if(s.empty()){// Return minimum value or -1 if empty
            return -1;
        }
        else{
            return mini;
        }
    }
};

int main() {
    SpecialStack s;
    s.push(5);
    cout << "Min: " << s.getMin() << endl; // Min: 5
    s.push(3);
    cout << "Min: " << s.getMin() << endl; // Min: 3
    s.push(7);
    cout << "Min: " << s.getMin() << endl; // Min: 3
    s.push(2);
    cout << "Min: " << s.getMin() << endl; // Min: 2
    cout << "Top: " << s.top() << endl; // Top: 2
    s.pop();
    cout << "Min: " << s.getMin() << endl; // Min: 3
    cout << "Top: " << s.top() << endl; // Top: 7
    s.pop();
    s.pop();
    cout << "Min: " << s.getMin() << endl; // Min: 5
    cout << "Is Empty: " << s.isEmpty() << endl; // Is Empty: 0 (false)
    return 0;
}