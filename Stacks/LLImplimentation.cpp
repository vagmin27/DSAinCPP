#include <bits/stdc++.h>
using namespace std;
struct StackNode {
    int data;
    StackNode* next;
    StackNode(int val) : data(val), next(nullptr) {}
};

class MyStack {
private:
    StackNode* top;

public:
    MyStack() : top(nullptr) {}

    void push(int x) {
        StackNode* newNode = new StackNode(x);
        newNode->next = top; // Link the new node to the previous top
        top = newNode; // Update top to the new node
    }

    int pop() {
        if (top == nullptr) {
            throw out_of_range("Stack is empty"); // Handle underflow
        }
        int poppedValue = top->data; // Store the value to return
        StackNode* temp = top; // Temporarily hold the top node
        top = top->next; // Move top to the next node
        delete temp; // Delete the old top node
        return poppedValue; // Return the popped value
    }

    bool isEmpty() {
        return top == nullptr; // Check if stack is empty
    }

    int peek() {
        if (top == nullptr) {
            throw out_of_range("Stack is empty"); // Handle empty stack
        }
        return top->data; // Return the top value without removing it
    }
};
int main() {
    MyStack stack;
    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element is: " << stack.peek() << endl; // Should output 30
    // Pop elements from the stack
    cout << "Popped element: " << stack.pop() << endl; // Should output 30
    cout << "Popped element: " << stack.pop() << endl; // Should output 20
    // Check if the stack is empty
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Should output No
    // Pop the last element
    cout << "Popped element: " << stack.pop() << endl; // Should output 10
    // Check if the stack is empty again
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Should output Yes
    // Uncommenting the following line will throw an exception since the stack is empty
    // cout << "Popped element: " << stack.pop() << endl;
    return 0;
}