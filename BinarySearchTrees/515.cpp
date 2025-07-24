#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;  // If the tree is empty, return an empty vector
        queue<TreeNode*> q;
        q.push(root);  // Start the BFS with the root node
        while (!q.empty()) {
            int sz = q.size();  // Number of nodes at the current level
            int maxi = INT_MIN;  // Initialize the largest value for this level
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);  // Push left child to the queue if it exists
                if (node->right) q.push(node->right);  // Push right child to the queue if it exists
                maxi = max(maxi, node->val);  // Update the largest value in this level
            }
            ans.push_back(maxi);  // Add the largest value of the level to the result
        }
        return ans;  // Return the vector with largest values for each level
    }
};
int main() {
    // Create a simple binary tree:
    //        1
    //      /   \
    //     3     2
    //    / \     \
    //   5   3     9
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    Solution solution;
    vector<int> result = solution.largestValues(root);
    // Output the result
    cout << "Largest values in each row: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}