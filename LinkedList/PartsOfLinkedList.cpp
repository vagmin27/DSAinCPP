#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int length = 0;
    ListNode* temp = head;
    while (temp) {
        ++length;
        temp = temp->next;
    }
    int base_size = length / k;
    int extra_parts = length % k;
    vector<ListNode*> result(k, nullptr);
    ListNode* current = head;
    ListNode* prev = nullptr;
    for (int i = 0; i < k; ++i) {
        result[i] = current;
        int current_part_size = base_size+(i<extra_parts?1:0);
        for (int j = 0; j < current_part_size; ++j) {
            prev = current;
            current = current->next;
        }
        if (prev) {
            prev->next = nullptr;
        }
    }
    return result;
}
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void printResult(const vector<ListNode*>& parts) {
    for (const auto& part : parts) {
        printList(part);
    }
}
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 3;
    vector<ListNode*> parts = splitListToParts(head, k);
    printResult(parts);
    return 0;
}