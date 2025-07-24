#include <bits/stdc++.h>
using namespace std;
class MyStack {
public:
    queue<int> q;
    MyStack() {}
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    int top() {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top element: " << stack.top() << endl; // Should print 3
    cout << "Popped element: " << stack.pop() << endl; // Should print 3
    cout << "New top element: " << stack.top() << endl; // Should print 2
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Should print No
    stack.pop(); // Pops 2
    stack.pop(); // Pops 1
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Should print Yes
    return 0;
}