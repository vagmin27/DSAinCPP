#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    vector<int> data;
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return data[k - 1];
    }
private:
    void inorder(TreeNode* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        data.push_back(root->val);
        inorder(root->right);
    }
};
int main() {
    // Constructing the binary search tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    Solution sol;
    int k = 2;
    cout << "The " << k << "-th smallest element is: " << sol.kthSmallest(root, k) << endl;
    return 0;
}