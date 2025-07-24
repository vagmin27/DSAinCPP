#include <bits/stdc++.h>
using namespace std;
class SortedStack {
public:
    void sort() {
        if (s.empty()) {
            return;
        }
        int num = s.top();
        s.pop();
        sort();
        SortedInsert(num);
    }
    void push(int num) {
        s.push(num);
    }
    void print() {
        stack<int> temp = s;
        while (!temp.empty()){
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
private:
    stack<int> s;
    void SortedInsert(int num){
        if (s.empty() || s.top() <= num){
            s.push(num);
            return;
        }
        int n = s.top();
        s.pop();
        SortedInsert(num);
        s.push(n);
    }
};
int main() {
    SortedStack sortedStack;
    sortedStack.push(34);
    sortedStack.push(3);
    sortedStack.push(31);
    sortedStack.push(98);
    sortedStack.push(92);
    cout << "Original stack: ";
    sortedStack.print();
    sortedStack.sort();
    cout << "Sorted stack: ";
    sortedStack.print();
    return 0;
}