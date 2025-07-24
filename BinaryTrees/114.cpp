#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left) {
                TreeNode* pred = curr->left;
                // Find the rightmost node of the left subtree
                while (pred->right) {
                    pred = pred->right;
                }
                // Link the right subtree to the right of the left subtree
                pred->right = curr->right;
                // Move the left subtree to the right
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;  // Move to the next right node
        }
    }
};
// Helper function to print the flattened tree
void printFlattenedTree(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}
// Helper function to create a binary tree for testing
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    return root;
}
int main() {
    // Create a sample tree:
    //        1
    //       / \
    //      2   5
    //     / \   \
    //    3   4   6
    TreeNode* root = createSampleTree();
    Solution solution;
    solution.flatten(root);
    // Print the flattened tree:
    // Expected output: 1 2 3 4 5 6
    printFlattenedTree(root);
    return 0;
}