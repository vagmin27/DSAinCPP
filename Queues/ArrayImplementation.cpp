#include <bits/stdc++.h>
using namespace std;
class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
        size = 1000001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    ~Queue() {
        delete[] arr;
    }
    bool isEmpty() {
        return qfront == rear;
    }

    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is full" << endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        else {
            int ans = arr[qfront];
            qfront++;
            if (qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if (isEmpty()) {
            return -1;
        }
        else {
            return arr[qfront];
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout << "Front element: " << q.front() << endl; // should print 10
    cout << "Dequeued: " << q.dequeue() << endl; // should print 10
    cout << "Front element after dequeue: " << q.front() << endl; // should print 20
    return 0;
}