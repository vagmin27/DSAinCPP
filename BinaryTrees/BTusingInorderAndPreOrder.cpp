#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function to create a map of node values to their indices in inorder array
    void createMapping(vector<int>& inorder, map<int, int>& nodeToIndex, int n) {
        for (int i = 0; i < n; i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }
    // Main function to build the tree
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        int preorderIndex = 0;
        map<int, int> nodeToIndex;
        int n = inorder.size();
        // Create a map from inorder elements to their indices
        createMapping(inorder, nodeToIndex, n);
        // Call the recursive helper function to construct the tree
        return solve(inorder, preorder, preorderIndex, 0, n - 1, nodeToIndex);
    }
    // Recursive function to construct the binary tree
    Node* solve(vector<int>& inorder, vector<int>& preorder, int& index, int inorderStart, int inorderEnd, map<int, int>& nodeToIndex) {
        // Base case: if the start index is greater than the end index
        if (inorderStart > inorderEnd) {
            return nullptr;
        }
        // Get the root element from preorder (using preorder index and then incrementing it)
        int element = preorder[index++];
        // Create a new node for the root
        Node* root = new Node(element);
        // Find the index of the root element in the inorder array
        int position = nodeToIndex[element];
        // Recursively build the left subtree and right subtree
        root->left = solve(inorder, preorder, index, inorderStart, position - 1, nodeToIndex);
        root->right = solve(inorder, preorder, index, position + 1, inorderEnd, nodeToIndex);
        // Return the constructed tree
        return root;
    }
    // Helper function to print inorder traversal of the tree
    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }
};

int main() {
    // Example input: Preorder and Inorder traversals
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    // Create an object of Solution class
    Solution sol;
    // Build the tree
    Node* root = sol.buildTree(inorder, preorder);
    // Print the inorder traversal of the constructed tree
    cout << "Inorder Traversal of the constructed tree: ";
    sol.inorderTraversal(root);
    cout << endl;
    return 0;
}