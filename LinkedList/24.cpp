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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* nextNode = head->next;
        head->next = swapPairs(nextNode->next);
        nextNode->next = head;
        return nextNode;
    }
};
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution solution;
    ListNode* swappedHead = solution.swapPairs(head);
    printList(swappedHead);
    while (swappedHead) {
        ListNode* temp = swappedHead;
        swappedHead = swappedHead->next;
        delete temp;
    }
    return 0;
}