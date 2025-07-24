#include <bits/stdc++.h>
using namespace std;
// Node structure definition
struct node {
    int data;
    struct node *left;
    struct node *right;

    node(int value) : data(value), left(NULL), right(NULL) {}
};
// Function to create a new node
node* newNode(int data) {
    return new node(data);  // Use `new` instead of `malloc`
}
// Solution class with the tree creation method
class Solution {
public:
    void create_tree(node* root0, vector<int>& vec) {
        // Using a queue to keep track of nodes to assign children
        queue<node*> q;
        q.push(root0);
        // Index to traverse the array vec
        int index = 1;
        while (!q.empty() && index < vec.size()) {
            node* current = q.front();
            q.pop();
            // If the left child exists, create it and push to queue
            if (index < vec.size()) {
                current->left = newNode(vec[index]);
                q.push(current->left);
                index++;
            }
            // If the right child exists, create it and push to queue
            if (index < vec.size()) {
                current->right = newNode(vec[index]);
                q.push(current->right);
                index++;
            }
        }
    }
    // Utility function to print the tree in-order (for testing purposes)
};

int main() {
    // Vector of integers to construct the binary tree
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    // Create the root of the tree
    node* root = newNode(vec[0]);
    // Create the tree from the vector
    Solution solution;
    solution.create_tree(root, vec);
    cout << endl;
    return 0;
}