#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    // Helper function to check if the tree is balanced and to return the height
    pair<bool, int> isBalancedOrNot(TreeNode* root) {
        if (root == nullptr) {
            return make_pair(true, 0);  // A null node is balanced with height 0
        }
        // Recursively check the left and right subtrees
        pair<bool, int> left = isBalancedOrNot(root->left);
        pair<bool, int> right = isBalancedOrNot(root->right);
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second - right.second) <= 1; // Check if height difference is <= 1
        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1; // Calculate the height of the current tree
        // If both left and right subtrees are balanced and the height difference is within limit, the tree is balanced
        if (leftAns && rightAns && diff) {
            ans.first = true;
        }
        else {
            ans.first = false;
        }
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedOrNot(root).first;
    }
};
int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    // Create a Solution object
    Solution solution;
    // Check if the tree is balanced
    bool result = solution.isBalanced(root);
    if (result) {
        cout << "The tree is balanced." << endl;
    }
    else {
        cout << "The tree is not balanced." << endl;
    }
    // Delete the dynamically allocated tree to prevent memory leaks (optional for this test case)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}