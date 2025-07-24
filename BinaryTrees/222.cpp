#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = findHeightLeft(root);
        int rightHeight = findHeightRight(root);
        // If the left and right heights are the same, it means this subtree is a perfect binary tree.
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;  // 2^leftHeight - 1
        }
        // If the heights differ, recursively count nodes in the left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
private:
    // Find the height of the leftmost path
    int findHeightLeft(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }
    // Find the height of the rightmost path
    int findHeightRight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
};
int main() {
    // Create a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    // Create solution object
    Solution solution;
    // Call countNodes function
    int result = solution.countNodes(root);
    // Print the result
    cout << "Number of nodes in the tree: " << result << endl;
    // Cleanup memory (in a real program, you'd likely want to delete nodes to avoid memory leaks)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}