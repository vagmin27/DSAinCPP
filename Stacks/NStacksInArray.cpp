#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    Node* next;  // Pointer to the next node in the linked list
    int index;   // Index of the element in the array
    Node(int x) {
        index = x;  // Initialize the index
        next = NULL; // Initialize the next pointer to NULL
    }
};
class NStack {
public:
    stack<int> freespots; // Stack to track free spots in the array
    int* arr;             // Array to store stack elements
    Node** top;           // Array of pointers to the top nodes of each stack
    // Constructor to initialize the NStack
    NStack(int N, int S) {
        arr = new int[S];         // Create the array of size S
        top = new Node*[N];       // Create an array of Node pointers for N stacks
        for (int i = 0; i < N; i++)
            top[i] = NULL;        // Initialize all tops to NULL
        for (int i = 0; i < S; i++)
            freespots.push(i);    // Fill freespots with all indices
    }
    // Push an element onto the Mth stack
    bool push(int x, int m) {
        // Check if there are free spots available
        if (freespots.empty())
            return false;
        // Store the value in the array at the free index
        arr[freespots.top()] = x;
        // Create a new node for the current index
        Node* temp = new Node(freespots.top());
        // Link the new node to the previous top
        temp->next = top[m - 1];
        // Update the top pointer for the stack
        top[m - 1] = temp;
        // Remove the index from the free spots
        freespots.pop();
        return true;
    }
    // Pop an element from the Mth stack
    int pop(int m) {
        // Check if the stack is empty
        if (top[m - 1] == NULL)
            return -1;
        // Get the index of the top element
        int element = arr[top[m - 1]->index];
        // Push the index back to the free spots
        freespots.push(top[m - 1]->index);
        // Move the top pointer to the next node
        top[m - 1] = top[m - 1]->next;
        return element;
    }
    // Destructor to free allocated memory
    ~NStack() {
        delete[] arr;
        for (int i = 0; i < sizeof(top) / sizeof(top[0]); i++) {
            while (top[i] != NULL) {
                Node* temp = top[i];
                top[i] = top[i]->next;
                delete temp; // Free each node
            }
        }
        delete[] top; // Free the top array
    }
};
int main() {
    // Create an instance of NStack with 3 stacks and a size of 10
    NStack stacks(3, 10);
    // Test pushing elements
    cout << "Pushing elements onto stacks:\n";
    cout << (stacks.push(10, 1) ? "Pushed 10 into Stack 1\n" : "Stack 1 is full\n");
    cout << (stacks.push(20, 2) ? "Pushed 20 into Stack 2\n" : "Stack 2 is full\n");
    cout << (stacks.push(30, 3) ? "Pushed 30 into Stack 3\n" : "Stack 3 is full\n");
    // Test popping elements
    cout << "\nPopping elements from stacks:\n";
    cout << "Popped from Stack 1: " << stacks.pop(1) << endl; // Should return 10
    cout << "Popped from Stack 2: " << stacks.pop(2) << endl; // Should return 20
    cout << "Popped from Stack 3: " << stacks.pop(3) << endl; // Should return 30
    // Test underflow
    cout << "Popped from Stack 1 (should be -1): " << stacks.pop(1) << endl; // Should return -1
    return 0;
}