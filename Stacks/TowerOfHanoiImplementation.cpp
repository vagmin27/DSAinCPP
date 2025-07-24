#include<bits/stdc++.h>
using namespace std;
void moveDisk(int disk, char from, char to) {
    cout << "Move disk " << disk << " from " << from << " to " << to << endl;
}
void towerOfHanoi(int n, char from, char to, char aux, vector<stack<int>>& pegs) {
    // Base case: only one disk, move it directly
    if (n == 1) {
        moveDisk(n, from, to);
        pegs[to - 'A'].push(pegs[from - 'A'].top());
        pegs[from - 'A'].pop();
        return;
    }
    // Move top n-1 disks from 'from' to 'aux' using 'to' as auxiliary
    towerOfHanoi(n - 1, from, aux, to, pegs);
    // Move the nth disk from 'from' to 'to'
    moveDisk(n, from, to);
    pegs[to - 'A'].push(pegs[from - 'A'].top());
    pegs[from - 'A'].pop();
    // Move n-1 disks from 'aux' to 'to' using 'from' as auxiliary
    towerOfHanoi(n - 1, aux, to, from, pegs);
}
int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    // Initialize pegs (A, B, C)
    vector<stack<int>> pegs(3);
    // Place all disks on peg A (assuming disks are numbered 1 to n from top to bottom)
    for (int i = n; i >= 1; --i) {
        pegs[0].push(i);
    }
    cout << "Initial state of the pegs:" << endl;
    cout << "Peg A: ";
    for (int i = n; i >= 1; --i) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Peg B: (empty)" << endl;
    cout << "Peg C: (empty)" << endl;
    // Perform the Tower of Hanoi
    towerOfHanoi(n, 'A', 'C', 'B', pegs);
    cout << "Final state of the pegs:" << endl;
    cout << "Peg A: ";
    while (!pegs[0].empty()) {
        cout << pegs[0].top() << " ";
        pegs[0].pop();
    }
    cout << endl;
    cout << "Peg B: ";
    while (!pegs[1].empty()) {
        cout << pegs[1].top() << " ";
        pegs[1].pop();
    }
    cout << endl;
    cout << "Peg C: ";
    while (!pegs[2].empty()) {
        cout << pegs[2].top() << " ";
        pegs[2].pop();
    }
    cout << endl;
    return 0;
}