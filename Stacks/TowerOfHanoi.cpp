#include <iostream>
using namespace std;
// Function to perform the Tower of Hanoi
void towerOfHanoi(int n, char source, char dest, char pseudo) {
    // Base case: only one disk
    if (n == 1) {
        cout << "Move disk 1 from "<<source<<" to "<<dest<<endl;
        return;
    }
    // Move n-1 disks from source to pseudo
    towerOfHanoi(n - 1, source, pseudo, dest);
    // Move the nth disk from source to dest
    cout << "Move disk " << n << " from " << source << " to " << dest << endl;
    // Move n-1 disks from pseudo to dest
    towerOfHanoi(n - 1, pseudo, dest, source);
}
int main() {
    int n; // Number of disks
    cout << "Enter the number of disks: ";
    cin >> n;
    // A, B and C are names of rods
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}