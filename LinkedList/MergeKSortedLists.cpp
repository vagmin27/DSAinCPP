#include<bits/stdc++.h>
#include <limits.h>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(INT_MAX);
        ListNode* prev = ans;
        bool rotate = true;

        while (rotate) {
            int idx = -1;
            int val = INT_MAX;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i]) {
                    if (val > lists[i]->val) {
                        idx = i;
                        val = lists[i]->val;
                    }
                }
            }
            if (idx == -1) return ans->next; // No more nodes to merge
            prev->next = lists[idx];
            prev = lists[idx];
            lists[idx] = lists[idx]->next; // Move to next node in the chosen list
        }
        return ans->next; // Return the merged list
    }
};
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         vector<ListNode*> nodes;
//         for(auto x : lists) {
//             for(auto l = x; l ; l = l -> next) nodes.push_back(l);
//         }

//         if(nodes.size() == 0) return nullptr;
//         sort(nodes.begin(), nodes.end(), [&](auto a, auto b) {
//             return a -> val < b -> val;
//         });

//         for(int i = 0; i < nodes.size() - 1; i++)
//             nodes[i]->next = nodes[i+1];
        
//         nodes[nodes.size() - 1]-> next = nullptr;
//         return nodes[0];
//     }
// };
void printList(ListNode* node) {
    while (node) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "nullptr" << endl;
}
ListNode* createList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
int main() {
    Solution solution;
    // Create some sample linked lists
    vector<ListNode*> lists;
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));
    // Merge the k sorted lists
    ListNode* mergedList = solution.mergeKLists(lists);
    // Print the merged linked list
    cout << "Merged List: ";
    printList(mergedList);
    // Clean up the allocated memory (not shown for simplicity)
    return 0;
}