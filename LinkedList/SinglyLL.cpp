#include <iostream>
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
            delete next;
            this->next = nullptr;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};
void InsertAtHead(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
    if (tail == nullptr) {  // if the list was empty
        tail = head;
    }
}
void InsertAtTail(Node*& tail, Node*& head, int d) {
    Node* temp = new Node(d);
    if (tail != nullptr) {
        tail->next = temp;
    } else {
        head = temp;  // if the list was empty, set head
    }
    tail = temp;
}
void InsertAtPosition(Node*& tail, Node*& head, int position, int d) {
    if (position <= 0) return;  // invalid position
    if (position == 1) {
        InsertAtHead(head, tail, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != nullptr) {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr) {
        // Position is greater than the length of the list, insert at tail
        InsertAtTail(tail, head, d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
    if (nodeToInsert->next == nullptr) { // if inserted at the end
        tail = nodeToInsert;
    }
}
void deleteNode(int pos, Node*& head) {
    if (head == nullptr) return; // Check for empty list
    // Deleting at head
    if (pos == 1) {
        Node* curr = head;
        head = head->next;
        curr->next = nullptr; // Avoid dangling pointer
        delete curr;
        return;
    }
    else {
        // Deleting all other nodes
        Node* curr = head;
        Node* prev = nullptr;
        int cnt = 1;
        while (cnt < pos && curr != nullptr) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr == nullptr) return; // Position exceeds length
        prev->next = curr->next;
        curr->next = nullptr; // Avoid dangling pointer
        delete curr;
    }
}
void print(Node*& head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    // Insert at head
    InsertAtHead(head, tail, 10);
    InsertAtHead(head, tail, 11);
    InsertAtHead(head, tail, 12);
    InsertAtHead(head, tail, 13);
    print(head);
    // Insert at tail
    InsertAtTail(tail, head, 9);
    InsertAtTail(tail, head, 8);
    InsertAtTail(tail, head, 7);
    print(head);
    // Insert at Middle
    InsertAtPosition(tail, head, 3, 22);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    deleteNode(1, head);
    print(head);
    // Clean up remaining nodes
    delete head; // This will recursively delete the rest
    return 0;
}