#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
// class Solution {
// public:
//     Node* segregate(Node* head) {
//         int zero = 0, one = 0, two = 0;
//         Node* temp = head;
//         // Count the number of 0s, 1s, and 2s
//         while (temp != nullptr) {
//             if (temp->data == 0) {
//                  zero++;
//             } else if (temp->data == 1) {
//                 one++;
//             } else if (temp->data == 2) {
//                 two++;
//             }
//             temp = temp->next;
//         }
//         // Update the linked list based on counts
//         temp = head;
//         while (temp != nullptr) {
//             if (zero > 0) {
//                 temp->data = 0;
//                 zero--;
//             } else if (one > 0) {
//                 temp->data = 1;
//                 one--;
//             } else if (two > 0) {
//                 temp->data = 2;
//                 two--;
//             }
//             temp = temp->next;
//         }
//         return head;
//     }
//     // Function to print the linked list
//     void printList(Node* head) {
//         Node* temp = head;
//         while (temp != nullptr) {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };
void insertAtTail(Node* &tail,Node* curr){
    tail->next=curr;
    tail=curr;
}
Node* sortList(Node* head){
    Node* zHead= new Node(-1);
    Node* zTail=zHead;
    Node* oHead= new Node(-1);
    Node* oTail=oHead;
    Node* tHead= new Node(-1);
    Node* tTail=tHead;
    Node* curr=head;
    while(curr!=nullptr){
        int val=curr->data;
        if(val==0){
            insertAtTail(zTail,curr);
        }
        if(val==1){
            insertAtTail(oTail,curr);
        }
        else if(val==2){
            insertAtTail(tTail,curr);
        }
        curr=curr->next;
    }
    //Merge 3 sublists
    if(oHead->next!=NULL){
        zTail->next=oHead->next;
    }
    else{
        zTail->next=tHead->next;
    }
    oTail->next=tHead->next;
    tTail->next=NULL;
    //setup head
    head=zHead->next;
    //delete dummy nodes
    delete zHead;
    delete oHead;
    delete tHead;
    return head;
}
void printList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
int main() {
    // Solution sol;
    // Creating a linked list: 1 -> 0 -> 2 -> 1 -> 0 -> 2
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(2);
    cout << "Original linked list: ";
    // sol.printList(head);
    // head = sol.segregate(head);
    head=sortList(head);
    cout << "Sorted linked list: ";
    printList(head);
    // Freeing the allocated memory
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}