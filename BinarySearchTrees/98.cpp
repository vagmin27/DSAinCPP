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
    bool check(TreeNode* root, long long m, long long M) {
        if (root == NULL) {
            return true;
        }
        if (root->val > m && root->val < M) {
            bool left = check(root->left, m, root->val);
            bool right = check(root->right, root->val, M);
            return left && right;
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    Solution solution;
    
    // Example: Creating a valid BST
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    // Test if the tree is a valid BST
    if (solution.isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    }
    else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    return 0;
}
