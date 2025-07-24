#include<bits/stdc++.h>
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
Node* reverse1(Node* head){
    if(head==NULL ||head->next==NULL){
        return head;
    }
    Node* head2=reverse1(head->next);
    head->next->next=head;
    head->next=NULL;
}
Node* reverseList(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    reverse1(head);
    return head;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Original list: ";
    printList(head);
    head = reverseList(head);
    cout << "Reversed list: ";
    printList(head);
}