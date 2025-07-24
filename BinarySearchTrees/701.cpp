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
    // Function to insert a node into a BST
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }
        else {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}
int main() {
    Solution solution;
    // Create an empty BST (initial root is NULL)
    TreeNode* root = NULL;
    // Insert nodes into the BST
    root = solution.insertIntoBST(root, 5);
    root = solution.insertIntoBST(root, 3);
    root = solution.insertIntoBST(root, 7);
    root = solution.insertIntoBST(root, 2);
    root = solution.insertIntoBST(root, 4);
    root = solution.insertIntoBST(root, 6);
    root = solution.insertIntoBST(root, 8);
    // Print the BST using in-order traversal
    cout << "BST after insertions (In-order traversal): ";
    inorder(root);
    cout << endl;
    return 0;
}