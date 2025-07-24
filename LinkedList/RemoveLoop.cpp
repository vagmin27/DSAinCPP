#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};
class Solution {
    Node* hasCycle(Node *head) {
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return slow;
            }
        }
        return NULL;
    }
    Node *detectCycle(Node *head) {
        if(head==NULL) return NULL;
        Node* temp=hasCycle(head);
        if (temp == NULL) return NULL;
        Node* slow=head;
        while(slow!=temp){
            slow=slow->next;
            temp=temp->next;
        }
        return slow;
    }
    public:
    void removeLoop(Node* head){
        if(head==NULL) return;
        Node* start=detectCycle(head);
        Node* temp=start;
        while(temp->next!=start){
            temp=temp->next;
        }
        temp->next=NULL;
    }
};
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout<<endl;
}
int main() {
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    head->next->next->next->next = head->next; // Create a cycle
    Solution s;
    s.removeLoop(head); // Remove the loop
    cout << "List after removing the cycle: ";
    printList(head);
    delete head->next->next;
    delete head->next;
    delete head;
    return 0;
}