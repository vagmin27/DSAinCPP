#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
Node* solve(Node* root, int &k, int node) {
    // Base case: If the root is NULL, return NULL.
    if (root == NULL) {
        return NULL;
    }
    // If the current node is the target node, return it.
    if (root->data == node) {
        return root;
    }
    // Recursively search in the left and right subtrees.
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    // If the node is found in the left subtree
    if (leftAns != NULL && rightAns == NULL) {
        // Decrease the count of steps for ancestor.
        k--;
        // If k becomes 0, the current root is the kth ancestor.
        if (k <= 0) {
            return root;
        }
        return leftAns;
    }
    // If the node is found in the right subtree
    if (rightAns != NULL && leftAns == NULL) {
        k--;
        // If k becomes 0, the current root is the kth ancestor.
        if (k <= 0) {
            return root;
        }
        return rightAns;
    }
    // If both left and right are non-NULL, it means the current node is the LCA.
    if (leftAns != NULL && rightAns != NULL) {
        return root;  // LCA case, so return the current root node.
    }
    // If the node is not found in either subtree, return NULL.
    return NULL;
}
int kthAncestor(Node* root, int k, int node) {
    // Start the search for kth ancestor.
    Node* ans = solve(root, k, node);
    // If the answer is NULL or the root node is the target node itself, return -1.
    if (ans == NULL || ans->data == node) {
        return -1;
    }
    return ans->data;
}
int main() {
    // Construct the binary tree.
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    int k = 2;
    int node = 4;
    int ancestor = kthAncestor(root, k, node);
    cout << "The " << k << "-th ancestor of node " << node << " is: " << ancestor << endl;
    return 0;
}