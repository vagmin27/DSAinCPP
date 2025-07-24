#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;
        bool leftToRight = true;
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize);
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                // Determine the position in the current level
                int index = leftToRight ? i : (levelSize - 1 - i);
                level[index] = node->val;
                // Push left and right children to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            // Add the current level to the result
            result.push_back(level);
            // Flip the direction for the next level
            leftToRight = !leftToRight;
        }
        return result;
    }
};
// Helper function to create a binary tree for testing
TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}
int main() {
    Solution sol;
    TreeNode* root = createTree();
    vector<vector<int>> result = sol.zigzagLevelOrder(root);
    // Print the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}