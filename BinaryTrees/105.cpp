#include <bits/stdc++.h>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        map<int, int> nodeToIndex;
        int n = inorder.size();
        createMapping(inorder, nodeToIndex, n);
        return solve(inorder, preorder, preorderIndex, 0, n - 1, nodeToIndex);
    }

    void createMapping(vector<int>& inorder, map<int, int>& nodeToIndex, int n) {
        for (int i = 0; i < n; i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& preorder, int& index,
                    int inorderStart, int inorderEnd, map<int, int>& nodeToIndex) {
        if (inorderStart > inorderEnd) {
            return nullptr;
        }
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];
        root->left = solve(inorder, preorder, index, inorderStart, position - 1, nodeToIndex);
        root->right = solve(inorder, preorder, index, position + 1, inorderEnd, nodeToIndex);
        return root;
    }
};

void printTree(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);
    cout << "In-order traversal of the reconstructed tree: ";
    printTree(root);  // Should print the inorder sequence: 9 3 15 20 7
    cout << endl;
    return 0;
}