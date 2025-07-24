#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    // Helper function to find the minimum value node in the right subtree
    int minValue(TreeNode* root) {
        TreeNode* temp = root;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp->val;
    }

public:
    // Function to delete a node from the BST
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return root;
        }
        if (root->val == key) {
            // 0 child: Node is a leaf node
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            // 1 child: Left child only
            if (root->left != NULL && root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // 1 child: Right child only
            if (root->left == NULL && root->right != NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // 2 children: Find the minimum value in the right subtree
            if (root->left != NULL && root->right != NULL) {
                int mini = minValue(root->right);
                root->val = mini;
                root->right = deleteNode(root->right, mini); // Recursively delete the in-order successor
                return root;
            }
        }
        else if (root->val > key) {
            root->left = deleteNode(root->left, key); // Recur on the left subtree
            return root;
        }
        else {
            root->right = deleteNode(root->right, key); // Recur on the right subtree
            return root;
        }
        return root;
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
    // Create a sample BST:
    //          5
    //         / \
    //        3   6
    //       / \
    //      2   4
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    Solution solution;
    // Print the tree before deletion
    cout << "Original BST (In-order traversal): ";
    inorder(root);
    cout << endl;
    // Delete node with key 3
    root = solution.deleteNode(root, 3);
    // Print the tree after deletion
    cout << "BST after deleting node 3 (In-order traversal): ";
    inorder(root);
    cout << endl;
    return 0;
}