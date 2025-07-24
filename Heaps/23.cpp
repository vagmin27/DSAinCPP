#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        // Comparator for the priority queue to create a min-heap
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap based on node values
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        // Push the first node of each list into the priority queue
        for (auto list : lists) {
            if (list != NULL) {
                pq.push(list);
            }
        }
        // Dummy node to help build the result list
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        // Process the priority queue to merge the lists
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            current->next = node;
            current = current->next;
            // If the current node has a next node, push it into the priority queue
            if (node->next != NULL) {
                pq.push(node->next);
            }
        }
        // Return the next of dummy node which is the head of the merged list
        return dummy->next;
    }
};
// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Helper function to create a linked list from a vector of integers
ListNode* createList(const vector<int>& values) {
    ListNode* head = new ListNode(0);
    ListNode* current = head;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return head->next;  // Returning the head of the list
}
int main() {
    Solution sol;
    // Create a vector of sorted linked lists
    vector<ListNode*> lists;
    // Example 1: List 1 -> 4 -> 5
    lists.push_back(createList({1, 4, 5}));
    // Example 2: List 1 -> 3 -> 4
    lists.push_back(createList({1, 3, 4}));
    // Example 3: List 2 -> 6
    lists.push_back(createList({2, 6}));
    // Merge the k sorted lists
    ListNode* mergedList = sol.mergeKLists(lists);
    // Print the merged list
    printList(mergedList);
    return 0;
}