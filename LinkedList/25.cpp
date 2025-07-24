#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int cnt = 0;
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == NULL) {
                return head; // Not enough nodes to reverse
            }
            temp = temp->next;
        }
        while (curr != NULL && cnt < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }
        return prev; // New head of the reversed group
    }
};
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " "; // Corrected from temp->data to temp->val
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "Original list: ";
    printList(head);
    Solution sol;
    int k = 2; // Example group size
    head = sol.reverseKGroup(head, k);
    cout << "Reversed in groups of " << k << ": ";
    printList(head);
    return 0;
}