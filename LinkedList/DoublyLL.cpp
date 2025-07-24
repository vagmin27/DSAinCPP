#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node() {
        int value = this->data;
        if (this->next != nullptr) {
            delete next;
            this->next = nullptr;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};
void print(Node* head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getLength(Node* head){
    int l=0;
    Node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}
void insertAtHead(Node* &head,Node* &tail ,int d){
    if (head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }else{
        Node* temp=new Node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void insertAtTail(Node* &tail,Node* &head, int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
        Node* temp=new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}
void insertAtPosition(Node* &head,Node* &tail,int pos,int d){
    if(pos==1){
        insertAtHead(head,tail,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        // Position is greater than the length of the list, insert at tail
        insertAtTail(tail,head,d);
        return;
    }
    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
}
void deleteNode(int pos,Node* head){
    if (head==nullptr) return; // Check for empty list
    // Deleting at head
    if (pos==1) {
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else {
        // Deleting all other nodes
        Node* curr=head;
        Node* prev=NULL;
        int cnt = 1;
        while(cnt<pos && curr!=nullptr) {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        if (curr==nullptr) return; // Position exceeds length
        curr->prev=nullptr;
        prev->next=curr->next;
        curr->next=nullptr; // Avoid dangling pointer
        delete curr;
    }
}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    cout<<getLength(head)<<endl;
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    //Insertion at head
    insertAtHead(head,tail,11);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    //Insertion at tail
    insertAtTail(tail,head,12);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    //Insertion at middle
    insertAtPosition(head,tail,2,13);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    deleteNode(1, head);
    print(head);
    // Clean up remaining nodes
    delete head; // This will recursively delete the rest
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
}