#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return mergeKListsDivideAndConquer(lists, 0, lists.size());
    }
private:
    ListNode* mergeKListsDivideAndConquer(vector<ListNode*>& lists, int leftIndex, int size) {
        if (size == 0) return nullptr;
        if (size == 1) return lists[leftIndex];
        int mid = size / 2;
        ListNode* left = mergeKListsDivideAndConquer(lists, leftIndex, mid);
        ListNode* right = mergeKListsDivideAndConquer(lists, leftIndex + mid, size - mid);
        return mergeTwoLists(left, right);
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head = nullptr;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        ListNode* curr = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = (l1 != nullptr) ? l1 : l2; // Attach the remaining part
        return head;
    }
};
ListNode* createList(const vector<int>& values) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy.next;
}
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}
int main() {
    Solution solution;
    // Create sample linked lists
    vector<ListNode*> lists;
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));
    // Merge the k sorted linked lists
    ListNode* mergedHead = solution.mergeKLists(lists);
    // Print the merged linked list
    printList(mergedHead);
    // Cleanup memory (not shown for simplicity, but should be handled)
    return 0;
}