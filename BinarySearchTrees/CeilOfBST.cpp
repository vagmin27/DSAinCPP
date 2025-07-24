#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// The findCeil function is as you've written it
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    // If the current node's data is equal to the input, return the input as the ceil
    if (root->data == input) {
        return input;
    }
    // If the current node's data is greater than the input, this could be a candidate for ceil
    if (root->data > input) {
        // Search in the left subtree to find if there's a smaller but valid ceil
        int leftCeil = findCeil(root->left, input);
        // If leftCeil is valid (not -1) and smaller than root's data, return leftCeil
        if (leftCeil != -1) {
            return leftCeil;
        }
        else {
            return root->data;  // Root is the ceil
        }
    }
    else {
        // If the current node's data is less than the input, search in the right subtree
        return findCeil(root->right, input);
    }
}

int main() {
    // Creating a simple BST
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    int input = 5;
    int ceilValue = findCeil(root, input);
    if (ceilValue != -1) {
        cout << "Ceil value for " << input << " is: " << ceilValue << endl;
    }
    else {
        cout << "No ceil value found for " << input << endl;
    }
    return 0;
}