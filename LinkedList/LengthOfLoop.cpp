#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
private:
    Node* hasCycle(Node *head) {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return slow;
            }
        }
        return nullptr;
    }

public:
    int countNodesinLoop(Node *head) {
        Node* intersection = hasCycle(head);
        if (intersection == nullptr) return 0;
        int count = 1;
        Node* curr = intersection;
        while (curr->next != intersection) {
            count++;
            curr = curr->next;
        }
        return count;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;
    Solution solution;
    int loopLength = solution.countNodesinLoop(head);
    if (loopLength > 0) {
        cout << "Length of loop: " << loopLength << endl;
    } else {
        cout << "No loop detected." << endl;
    }
}