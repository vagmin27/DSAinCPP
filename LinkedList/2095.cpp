#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// class Solution {
// private:
//     ListNode* getMid(ListNode* head) {
//         if (head == nullptr) return nullptr; // Handle empty list
//         ListNode* slow = head;
//         ListNode* fast = head->next;
//         while (fast != nullptr && fast->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow; // Mid node
//     }
//     void deleteNode(int pos, ListNode*& head) {
//         if (head == nullptr) return; // Check for empty list
//         // Deleting at head
//         if (pos == 1) {
//             ListNode* curr = head;
//             head = head->next;
//             delete curr; // Avoid dangling pointer
//             return;
//         }
//         else {
//             // Deleting all other nodes
//             ListNode* curr = head;
//             ListNode* prev = nullptr;
//             int cnt = 1;
//             while (cnt < pos && curr != nullptr) {
//                 prev = curr;
//                 curr = curr->next;
//                 cnt++;
//             }
//             if (curr == nullptr) return; // Position exceeds length
//             prev->next = curr->next;
//             delete curr; // Avoid dangling pointer
//         }
//     }
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if (head == nullptr || head->next == nullptr) {
//             delete head; // If there's only one node
//             return nullptr; // List becomes empty
//         }
//         ListNode* mid = getMid(head);
//         ListNode* curr = head;
//         int pos = 1;
//         // Find the position of the middle node
//         while (curr != mid) {
//             curr = curr->next;
//             pos++;
//         }
//         deleteNode(pos, head);
//         return head; // Return the modified list
//     }
// };
// class Solution {
// private:
//     pair<ListNode*, ListNode*> getMidAndPrev(ListNode* head) {
//         if (head == nullptr) 
//             return {nullptr, nullptr};
//         ListNode* slow = head;
//         ListNode* fast = head;
//         ListNode* prev = nullptr;   
//         while (fast != nullptr && fast->next != nullptr) {
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return {slow, prev};
//     }
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if (head == nullptr || head->next == nullptr) {
//             delete head;
//             return nullptr;
//         }
//         auto [mid, prev] = getMidAndPrev(head);
//         if (prev != nullptr) {
//             prev->next = mid->next;
//         }
//         delete mid;
//         return head;
//     }
// };
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head;
        ListNode* temp1=head;
        ListNode *temp2=head->next;
        int size=0;
        while(temp){
            size++;
            temp=temp->next;
        }
        if(size==1)
            return nullptr;
        size=size/2;
        int cnt=1;
        while(cnt<=size){
            if(cnt==size){
                temp1->next=temp2->next;
                temp2->next=NULL;
                break;
            }
            else{
                temp1=temp1->next;
                temp2=temp2->next;
            }
            cnt++;
        }
        return head;
    }
};
// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}
// Main function to test the implementation
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "Original list: ";
    printList(head);
    Solution solution;
    head = solution.deleteMiddle(head);
    cout << "List after deleting the middle node: ";
    printList(head);
    // Clean up remaining nodes
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}