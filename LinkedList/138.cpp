#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
    void insertAtTail(Node* &head, Node* &tail, int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* cloneH = NULL;
        Node* cloneT = NULL;
        Node* temp = head;
        // Step 1: Create a copy of each node and append to the clone list
        while (temp != NULL) {
            insertAtTail(cloneH, cloneT, temp->val);
            temp = temp->next;
        }
        // Step 2: Map original nodes to their clones
        unordered_map<Node*, Node*> mp;
        Node* orig = head;
        Node* clone = cloneH;
        while (orig != NULL) {
            mp[orig] = clone;
            orig = orig->next;
            clone = clone->next;
        }
        // Step 3: Set the random pointers in the cloned list
        orig = head;
        clone = cloneH;
        while (orig != nullptr) {
            clone->random = mp[orig->random];
            orig = orig->next;
            clone = clone->next;
        }
        // Return the head of the cloned list
        return cloneH; // Corrected return value
    }
};
// Function to print the list (for debugging)
void printList(Node* head) {
    while (head) {
        cout << "Value: " << head->val;
        if (head->random) {
            cout << ", Random Value: " << head->random->val;
        }
        else {
            cout << ", Random Value: NULL";
        }
        cout << endl;
        head = head->next;
    }
}
// Function to create a list for testing
Node* createList() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    head->random = third; // 1 -> 3
    second->random = head; // 2 -> 1
    third->random = second; // 3 -> 2
    fourth->random = second; // 4 -> 2
    return head;
}
int main() {
    Node* originalList = createList();
    cout << "Original list:" << endl;
    printList(originalList);
    Solution solution;
    Node* clonedList = solution.copyRandomList(originalList);
    cout << "\nCloned list:" << endl;
    printList(clonedList);
    // Clean up memory if needed (omitted for brevity)
    return 0;
}