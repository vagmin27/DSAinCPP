#include <bits/stdc++.h>
using namespace std;
class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;
public:
    // Initialize TwoStack.
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s; // top2 points to the end of the array
        arr = new int[s];
    }
    // Push in stack 1.
    void push1(int num) {
        if (top2 - top1 > 1) { // Check if there's space in stack 1
            top1++;
            arr[top1] = num;
        } else {
            cout << "Stack Overflow in Stack 1\n";
        }
    }
    // Push in stack 2.
    void push2(int num) {
        if (top2 - top1 > 1) { // Check if there's space in stack 2
            top2--;
            arr[top2] = num;
        } else {
            cout << "Stack Overflow in Stack 2\n";
        }
    }
    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            cout << "Stack Underflow in Stack 1\n";
            return -1; // Indicates stack is empty
        }
    }
    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 < size) { // Check if stack 2 is not empty
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            cout << "Stack Underflow in Stack 2\n";
            return -1; // Indicates stack is empty
        }
    }
};
int main() {
    TwoStack ts(10); // Create a TwoStack with size 10
    // Testing stack 1
    ts.push1(5);
    ts.push1(10);
    cout << "Popped from Stack 1: " << ts.pop1() << endl; // Should print 10
    cout << "Popped from Stack 1: " << ts.pop1() << endl; // Should print 5
    cout << "Popped from Stack 1: " << ts.pop1() << endl; // Should indicate underflow
    // Testing stack 2
    ts.push2(15);
    ts.push2(20);
    cout << "Popped from Stack 2: " << ts.pop2() << endl; // Should print 20
    cout << "Popped from Stack 2: " << ts.pop2() << endl; // Should print 15
    cout << "Popped from Stack 2: " << ts.pop2() << endl; // Should indicate underflow
    return 0;
}