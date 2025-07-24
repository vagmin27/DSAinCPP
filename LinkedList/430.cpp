#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node* child;
    Node() : val(0), next(NULL), prev(NULL), child(NULL) {}
    Node(int _val) : val(_val), next(NULL), prev(NULL), child(NULL) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* node = temp->next;
            if (temp->child != NULL) {
                Node* childNode = temp->child;
                temp->child = NULL;
                childNode = flatten(childNode);
                temp->next = childNode;
                childNode->prev = temp;
                while (childNode->next) {
                    childNode = childNode->next;
                }
                childNode->next = node;
                if (node) node->prev = childNode;
            }
            temp = node;
        }
        return head;
    }
};
int main() {
    // Create the nodes for the doubly linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    // Add child nodes for node 2
    head->next->child = new Node(4);
    head->next->child->next = new Node(5);
    head->next->child->next->prev = head->next->child;
    head->next->child->next->next = new Node(6);
    head->next->child->next->next->prev = head->next->child->next;
    // Add a child node for node 5
    head->next->child->next->child = new Node(7);
    // Flatten the list using Solution
    Solution solution;
    head = solution.flatten(head);
    // Output the flattened list
    Node* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}