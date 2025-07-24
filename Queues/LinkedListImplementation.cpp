#include<bits/stdc++.h>
using namespace std;

struct QueueNode {
    int data;
    QueueNode *next;
    QueueNode(int a) : data(a), next(NULL) {}
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    MyQueue() : front(NULL), rear(NULL) {}

    void push(int x);
    int pop();
};

// Function to push an element into the queue.
void MyQueue::push(int x) {
    QueueNode* temp = new QueueNode(x); // Create a new node
    if (rear == NULL) { // If the queue is empty
        front = rear = temp; // Both front and rear point to the new node
    } else {
        rear->next = temp; // Link the old rear to the new node
        rear = temp; // Update rear to the new node
    }
}

// Function to pop front element from the queue.
int MyQueue::pop() {
    if (front == NULL) { // If the queue is empty
        return -1; // Indicate that the queue is empty
    }
    QueueNode* temp = front; // Store the front node
    int data = front->data; // Get the data to return
    front = front->next; // Move front to the next node

    // If front becomes NULL, update rear to NULL as well
    if (front == NULL) {
        rear = NULL;
    }

    delete temp; // Free the memory of the popped node
    return data; // Return the popped data
}

int main() {
    MyQueue queue;
    // Test pushing elements into the queue
    queue.push(10);
    queue.push(20);
    queue.push(30);
    // Test popping elements from the queue
    cout<<"Popped: "<<queue.pop()<<endl; // Should print 10
    cout<<"Popped: "<<queue.pop()<<endl; // Should print 20
    cout<<"Popped: "<<queue.pop()<<endl; // Should print 30
    cout<<"Popped: "<<queue.pop()<<endl; // Should print -1 (queue is empty)
    return 0;
}