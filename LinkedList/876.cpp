#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};
class Solution {
public:
    Node* middleNode(Node* head) {
        if (head == NULL) {
            return head;
        }
        if (head->next == NULL) {
            return head;
        }
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Original list: ";
    printList(head);
    Solution solution;
    Node* middle = solution.middleNode(head);
    cout << "Middle node value: " << middle->val << endl;
    return 0;
}