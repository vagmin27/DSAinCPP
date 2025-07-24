#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* solve(vector<int>& preorder, int mini, int maxi, int& i) {
        if(i >= preorder.size()) {
            return NULL;
        }
        if(preorder[i] < mini || preorder[i] > maxi) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = solve(preorder, mini, root->val, i);
        root->right = solve(preorder, root->val, maxi, i);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i = 0;
        return solve(preorder, mini, maxi, i);
    }
};
// Helper function to print the tree (in-order traversal)
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};  // Example preorder traversal
    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);
    cout << "Inorder Traversal of the BST: ";
    inorder(root);
    cout << endl;
    return 0;
}