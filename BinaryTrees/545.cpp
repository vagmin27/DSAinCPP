#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    void traverseLeft(Node* root, vector<int>& ans) {
        // Base case: if the node is null or it is a leaf node, return
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }
        // Add the node's data to the answer vector
        ans.push_back(root->data);
        // Recur for the left or right subtree, depending on the presence of left child
        if (root->left) {
            traverseLeft(root->left, ans);
        } else {
            traverseLeft(root->right, ans);
        }
    }
    void traverseLeaf(Node* root, vector<int>& ans) {
        // Base case: if the node is null, return
        if (root == nullptr) {
            return;
        }
        // If the node is a leaf, add it to the answer vector
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->data);
            return;
        }
        // Recur for both left and right subtrees
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    void traverseRight(Node* root, vector<int>& ans) {
        // Base case: if the node is null or it is a leaf node, return
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }
        // Recur for the right or left subtree, depending on the presence of right child
        if (root->right) {
            traverseRight(root->right, ans);
        } else {
            traverseRight(root->left, ans);
        }
        // Add the node's data to the answer vector after recursion to ensure right-to-left order
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        // If the tree is empty, return an empty vector
        if (root == nullptr) {
            return ans;
        }
        // Add the root node to the boundary
        ans.push_back(root->data);
        // Traverse the left boundary (excluding leaf nodes)
        if (root->left) {
            traverseLeft(root->left, ans);
        }
        // Traverse the leaf nodes (both left and right subtrees), excluding leaf nodes in left and right boundary
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        // Traverse the right boundary (excluding leaf nodes)
        if (root->right) {
            traverseRight(root->right, ans);
        }
        return ans;
    }
};
// Helper function to create a binary tree for testing
Node* createTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);
    return root;
}
int main() {
    Solution sol;
    Node* root = createTree();
    vector<int> result = sol.boundaryTraversal(root);
    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}