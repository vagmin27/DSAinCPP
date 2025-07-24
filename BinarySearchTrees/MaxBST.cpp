#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    // Constructor to create a new node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class info {
public:
    int maxi;      // Maximum value in the subtree
    int mini;      // Minimum value in the subtree
    bool isBST;    // If the subtree is a BST
    int size;      // Size of the subtree
};

class Solution {
private:
    info solve(Node* root, int &ans) {
        // Base case: If the node is NULL, return a valid BST with size 0
        if (root == NULL) {
            return {INT_MIN, INT_MAX, true, 0};
        }
        // Recursive calls for left and right subtrees
        info left = solve(root->left, ans);
        info right = solve(root->right, ans);
        // Initialize current node's info
        info currNode;
        currNode.size = left.size + right.size + 1;
        currNode.maxi = max(root->data, right.maxi);  // Maximum value in the current subtree
        currNode.mini = min(root->data, left.mini);   // Minimum value in the current subtree
        // Check if the current subtree is a BST
        if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
            currNode.isBST = true;
        }
        else {
            currNode.isBST = false;
        }
        // Update the answer if the current subtree is a BST
        if (currNode.isBST) {
            ans = max(ans, currNode.size);
        }
        
        return currNode;
    }
    
public:
    // Function to return the size of the largest BST in a binary tree
    int largestBst(Node *root) {
        int maxSize = 0;
        solve(root, maxSize);  // Start the recursion to find the largest BST
        return maxSize;
    }
};
int main() {
    // Create a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(20);
    Solution solution;
    int largestBST = solution.largestBst(root);
    cout << "Size of the largest BST: " << largestBST << endl;
    return 0;
}