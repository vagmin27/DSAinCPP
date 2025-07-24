#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
    ~Node() {
        int value = this->data;
        if (this->next != nullptr) {
            delete next; // recursively delete the next nodes
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};
void insertNode(Node* &tail, int e, int d) {
    Node* newNode = new Node(d);
    if (tail == nullptr) {
        // for empty list
        tail = newNode;
        newNode->next = newNode; // point to itself
    }
    else {
        // non-empty list
        Node* curr = tail;
        while (curr->next != tail && curr->data != e) {
            curr = curr->next;
        }
        if (curr->data == e) {
            newNode->next = curr->next;
            curr->next = newNode;
            if (curr == tail) { // if we inserted after the tail
                tail = newNode;
            }
        }
        else {
            cout << "Element " << e << " not found!" << endl;
            delete newNode; // avoid memory leak
        }
    }
}
void deleteNode(Node* &tail, int val) {
    // Empty list
    if (tail == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* prev = tail;
    Node* curr = prev->next;
    do {
        if (curr->data == val) {
            // Node found
            if (curr == tail && curr->next == tail) { // only one node
                delete curr;
                tail = nullptr; // list is now empty
            }
            else {
                prev->next = curr->next;
                if (curr == tail) { // if tail is to be deleted
                    tail = prev; // update tail
                }
                delete curr;
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (prev != tail);
    cout << "Element " << val << " not found!" << endl;
}
void print(Node* tail) {
    if (tail == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = tail->next; // start from the head
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}
int main() {
    Node* tail = nullptr;
    insertNode(tail, 5, 3); // Should say element not found
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 5, 6);
    print(tail);
    insertNode(tail, 3, 4);
    print(tail);
    deleteNode(tail, 3);
    print(tail);
    deleteNode(tail, 5);
    print(tail);
    deleteNode(tail, 7);
    print(tail);
    deleteNode(tail, 6);
    print(tail);
    deleteNode(tail, 4);
    print(tail);
    return 0;
}