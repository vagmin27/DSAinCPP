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
};
class Solution {
public:
    Node* removeDuplicates(Node* head) {
        if (head == NULL) return NULL; // Check for empty list
        Node* curr = head; // Start with the head
        while (curr != NULL && curr->next != NULL) {
            if (curr->data == curr->next->data) { // Check for duplicates
                Node* toDelete = curr->next; // Duplicate node to delete
                curr->next = curr->next->next; // Skip the duplicate
                delete toDelete; // Free memory
            } else {
                curr = curr->next; // Move to the next node
            }
        }
        return head; // Return the modified list
    }
};
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
Node* createList(const int arr[], int size) {
    if (size == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < size; ++i) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}
int main() {
    int arr[] = {1, 1, 2, 3, 3, 4, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* head = createList(arr, size);
    cout << "Original list: ";
    printList(head);
    Solution solution;
    head = solution.removeDuplicates(head);
    cout << "List after removing duplicates: ";
    printList(head);
    return 0;
}