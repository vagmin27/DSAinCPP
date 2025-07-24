#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
bool isCircular(Node* head) {
    if (head == NULL) {
        return true;
    }
    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    return temp == head;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void deleteList(Node* head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Original list: ";
    printList(head);
    cout << "Is circular: " << (isCircular(head) ? "Yes" : "No") << endl;
    // Create a circular list for testing
    head->next->next->next->next->next = head;  // Make the list circular
    cout << "Is circular after modification: " << (isCircular(head) ? "Yes" : "No") << endl;
    // Clean up memory
    // Note: In a circular list, you'd need a special method to avoid infinite loop in deletion.
    // For now, I'll skip deleting the circular list for demonstration purposes.
    // deleteList(head); // Uncomment if you make it non-circular before deletion.
    return 0;
}