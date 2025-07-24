#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;  // Queue to store nodes and their respective indices
        q.push(make_pair(root, 0));  // Initial node with index 0
        while (!q.empty()) {
            int size = q.size();
            long long mini = q.front().second;  // The index of the first node at the current level
            int first, last;
            for (int i = 0; i < size; i++) {
                long long currId = q.front().second - mini;  // Normalize current index to avoid overflow
                TreeNode* node = q.front().first;
                q.pop();
                // Mark the first and last node's index of the current level
                if (i == 0) {
                    first = currId;
                }
                if (i == size - 1) {
                    last = currId;
                }
                // Add the children of the current node to the queue with updated indices
                if (node->left) {
                    q.push(make_pair(node->left, currId * 2 + 1));
                }
                if (node->right) {
                    q.push(make_pair(node->right, currId * 2 + 2));
                }
            }
            // Update the maximum width
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};
// Main function to test the solution
int main() {
    // Create the binary tree:
    //           1
    //          / \
    //         3   2
    //        / \   \
    //       5   3   9
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    // Create an object of Solution and call the method
    Solution solution;
    cout << "Maximum width of the binary tree: " << solution.widthOfBinaryTree(root) << endl;
    return 0;
}