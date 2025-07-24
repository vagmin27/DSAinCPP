#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T data) {
        next = NULL;
        this->data = data;
    }
    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};
Node<int>* solve(Node<int>* first, Node<int>* second) {
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;
    Node<int>* curr2 = second;
    while (next1 != NULL && curr2 != NULL) {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
            curr1->next = curr2;
            Node<int>* next2 = curr2->next;  // Declare next2 here
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL) {
                curr1->next = curr2;  // Attach the remaining nodes
                return first; // Return the merged list
            }
        }
    }
    return first; // Return the merged list
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    if (first == NULL) return second;
    if (second == NULL) return first;
    // Start merging from the smaller head
    if (first->data <= second->data) {
        return solve(first, second);
    } else {
        return solve(second, first);
    }
}
void printList(Node<int>* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    // Create first linked list: 1 -> 3 -> 5
    Node<int>* first = new Node<int>(1);
    first->next = new Node<int>(3);
    first->next->next = new Node<int>(5);
    // Create second linked list: 2 -> 4 -> 6
    Node<int>* second = new Node<int>(2);
    second->next = new Node<int>(4);
    second->next->next = new Node<int>(6);
    // Merge the two sorted linked lists
    Node<int>* mergedHead = sortTwoLists(first, second);
    // Print the merged linked list
    printList(mergedHead);
    // Free allocated memory (optional, since the destructor will handle this)
    delete mergedHead; // This will delete the whole list
    return 0;
}