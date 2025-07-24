#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void inorder(TreeNode* root, vector<int>& in) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(root, in);
        int i = 0;
        int j = in.size() - 1;
        while (i < j) {
            int sum = in[i] + in[j];
            if (sum == k) return true;
            else if (sum > k) j--;
            else i++;
        }
        return false;
    }
};
int main() {
    // Create a simple binary search tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    Solution solution;
    int k = 9;
    if (solution.findTarget(root, k)) {
        cout << "Found two numbers that sum up to " << k << endl;
    }
    else {
        cout << "No two numbers found that sum up to " << k << endl;
    }
    return 0;
}