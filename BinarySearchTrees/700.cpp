#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    // Function to search for a value in the BST
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;  // If the node is NULL, return NULL (not found)
        }
        if (root->val == val) {
            return root;  // If the node's value matches the target, return the node
        }
        if (root->val < val) {
            return searchBST(root->right, val);  // If the target is greater, search in the right subtree
        } else {
            return searchBST(root->left, val);   // If the target is smaller, search in the left subtree
        }
    }
};
// Helper function to print in-order traversal of the tree
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}
int main() {
    Solution solution;
    // Create a sample BST:
    //          5
    //         / \
    //        3   7
    //       / \  / \
    //      2   4 6   8
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    // Print the BST using in-order traversal
    cout << "BST (In-order traversal): ";
    inorder(root);
    cout << endl;
    // Search for a value in the BST
    int target = 4;
    TreeNode* result = solution.searchBST(root, target);
    if (result != NULL) {
        cout << "Node with value " << target << " found: " << result->val << endl;
    } else {
        cout << "Node with value " << target << " not found" << endl;
    }
    target = 10;
    result = solution.searchBST(root, target);
    if (result != NULL) {
        cout << "Node with value " << target << " found: " << result->val << endl;
    }
    else {
        cout << "Node with value " << target << " not found" << endl;
    }
    return 0;
}