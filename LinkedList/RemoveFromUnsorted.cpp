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
};
Node* removeUnsorted(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    unordered_set<int> seen;
    Node* curr = head;
    Node* prev = nullptr;
    while (curr != nullptr) {
        if (seen.find(curr->data) != seen.end()) {
            // Duplicate found
            prev->next = curr->next;
            delete curr;  // Free memory of the duplicate node
            curr = prev->next; // Move to next node
        } else {
            // Not a duplicate
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
    return head; // Return the modified head
}
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(2);
    cout << "Original list: ";
    printList(head);
    head = removeUnsorted(head);
    cout << "List after removing duplicates: ";
    printList(head);
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}