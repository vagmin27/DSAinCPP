#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<int> st;
    int mini;

    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                st.push(2 * val - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        int m = st.top();
        st.pop();
        if (m < mini) {
            mini = 2 * mini - m;
        }
    }
    
    int top() {
        if (st.empty()) return -1; // Handle empty stack case
        int n = st.top();
        return (n < mini) ? mini : n;
    }
    
    int getMin() {
        return mini;
    }
};

int main() {
    MinStack minStack;

    minStack.push(3);
    minStack.push(5);
    cout << "Min: " << minStack.getMin() << endl; // Output: 3
    minStack.push(2);
    minStack.push(1);
    cout << "Min: " << minStack.getMin() << endl; // Output: 1
    minStack.pop();
    cout << "Top: " << minStack.top() << endl; // Output: 2
    cout << "Min: " << minStack.getMin() << endl; // Output: 2
    minStack.pop();
    cout << "Min: " << minStack.getMin() << endl; // Output: 3
    minStack.pop();
    cout << "Min: " << minStack.getMin() << endl; // Output: 3
    minStack.pop();
    return 0;
}