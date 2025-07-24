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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int& postorderIndex, int inorderStart, int inorderEnd,
                    map<int, int>& nodeToIndex) {
        if (inorderStart > inorderEnd) {
            return NULL;
        }
        int element = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];
        root->right = solve(inorder, postorder, postorderIndex, position + 1,
                            inorderEnd, nodeToIndex);
        root->left = solve(inorder, postorder, postorderIndex, inorderStart,
                            position - 1, nodeToIndex);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex = postorder.size() - 1;
        map<int, int> nodeToIndex;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            nodeToIndex[inorder[i]] = i;
        }
        return solve(inorder, postorder, postorderIndex, 0, n - 1, nodeToIndex);
    }
};
void printTree(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}
int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    Solution solution;
    TreeNode* root = solution.buildTree(inorder, postorder);
    cout << "In-order traversal of the reconstructed tree: ";
    printTree(root);  // Should print the inorder sequence: 9 3 15 20 7
    cout << endl;
    return 0;
}