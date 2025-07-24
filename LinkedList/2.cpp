#include<bits/stdc++.h>
using namespace std;
class ListNode {
public:
    int data;
    ListNode* next;
    ListNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
class Solution {
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* add(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        while (l1 != NULL || l2 != NULL || carry > 0) {
            int sum = carry;
            if (l1 != NULL) {
                sum += l1->data;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->data;
                l2 = l2->next;
            }
            int d = sum % 10;
            insertAtTail(ansHead, ansTail, d);
            carry = sum / 10;
        }
        return ansHead;
    }
    void insertAtTail(ListNode*& head, ListNode*& tail, int val) {
        ListNode* newNode = new ListNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* ans = add(l1, l2);
        return ans;
    }
};
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
int main() {
    // Creating a simple linked list: 1 -> 2 -> 3 -> 4 -> 5
    //List 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "Original lists: ";
    printList(head);
    cout<<" & ";
    //List 2
    ListNode* head1 = new ListNode(2);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(1);
    head1->next->next->next->next = new ListNode(5);
    printList(head1);
    Solution s;
    cout<<"Sum Of Two Numbers Represented by LinkedList: "<<s.addTwoNumbers(head,head1)<<endl;
}