#include <bits/stdc++.h>
using namespace std;
queue<int> InterleaveFirstHalfOfQueueWithSecondHalf(queue<int> q) {
    int n = q.size();
    if (n == 0) return q;  // Return empty queue if input is empty
    stack<int> s;
    // Push the first half of the queue into the stack
    for (int i = 0; i < n / 2; i++) {
        s.push(q.front());
        q.pop();
    }
    // Enqueue the elements from the stack back into the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    // Move the first half elements to the back of the queue
    for (int i = 0; i < n / 2; i++) {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    // Interleave the elements from the stack and the queue
    while (!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
        val = q.front();
        q.pop();
        q.push(val);
    }
    return q;  // Return the modified queue
}

int main() {
    queue<int> q;
    // Sample input
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q = InterleaveFirstHalfOfQueueWithSecondHalf(q);
    // Print the result
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}