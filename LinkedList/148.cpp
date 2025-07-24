#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0); // Create a dummy node to simplify merging
        ListNode* temp = dummy; // Pointer to build the merged list
        // Merge the two lists
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next; // Move to the next node
        }
        // If there are remaining nodes in either list, append them
        if (left != nullptr) {
            temp->next = left;
        } else {
            temp->next = right;
        }
        return dummy->next; // Return the merged list, which starts after the dummy
    }
    ListNode* getMid(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // Split the list into two halves
        left = sortList(left); // Sort the left half
        right = sortList(right); // Sort the right half
        return merge(left, right); // Merge the sorted halves
    }
};
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}
int main() {
    // Create a linked list: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    cout << "Original list: ";
    printList(head);
    Solution solution;
    ListNode* sortedList = solution.sortList(head);
    cout << "Sorted list: ";
    printList(sortedList);
    ListNode* current = sortedList;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
    return 0;
}