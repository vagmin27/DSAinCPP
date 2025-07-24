#include<bits/stdc++.h>
using namespace std;

class Solution {
    void insertAtBottom(stack<int>& St, int x) {
        if (St.empty()) {
            St.push(x);
            return;
        }
        int num = St.top();
        St.pop();
        insertAtBottom(St, x);
        St.push(num);
    }

public:
    void Reverse(stack<int>& St) {
        if (St.empty()) {
            return;
        }
        int num = St.top();
        St.pop();
        Reverse(St);
        insertAtBottom(St, num);
    }
};
int main() {
    stack<int> St;
    Solution sol;
    St.push(1);
    St.push(2);
    St.push(3);
    St.push(4);
    St.push(5);
    cout << "Original stack (top to bottom): ";
    stack<int> temp = St; // Copy for display
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    sol.Reverse(St);
    cout << "Reversed stack (top to bottom): ";
    while (!St.empty()) {
        cout << St.top() << " ";
        St.pop();
    }
    cout << endl;
    return 0;
}