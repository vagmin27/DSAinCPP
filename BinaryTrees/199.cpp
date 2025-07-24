#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void solve(TreeNode* root, vector<int>& ans, int level) {
        if (root == NULL) {
            return;
        }
        // If we are at a new level, we add the first encountered node (rightmost node) to the result
        if (level == ans.size()) {
            ans.push_back(root->val);
        }
        // First traverse the right subtree, then the left subtree
        solve(root->right, ans, level + 1);
        solve(root->left, ans, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};
class Sol {
private:
    void solved(TreeNode* root, vector<int>& ans, int level) {
        if (root == NULL) {
            return;
        }
        // If we are at a new level, we add the first encountered node (rightmost node) to the result
        if (level == ans.size()) {
            ans.push_back(root->val);
        }
        // First traverse the right subtree, then the left subtree
        solved(root->left, ans, level + 1);
        solved(root->right, ans, level + 1);
    }
public:
    vector<int> LeftSideView(TreeNode* root) {
        vector<int> ans;
        solved(root, ans, 0);
        return ans;
    }
};
int main() {
    // Construct the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    
    // Create a solution object and call the rightSideView function
    Solution solution;
    vector<int> result = solution.rightSideView(root);
    
    // Print the result
    cout << "Right side view of the binary tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    Sol sol;
    vector<int> result = sol.LeftSideView(root);
    // Print the result
    for (int val : result) {
        cout<<val<<" ";
    }
    return 0;
    // Cleanup memory (optional but good practice)
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}