#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // Helper function to track parent pointers
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack) {
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            if (current->left) {
                parentTrack[current->left] = current;
                queue.push(current->left);
            }
            if (current->right) {
                parentTrack[current->right] = current;
                queue.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;  // Maps child to parent
        markParent(root, parentTrack);  // Mark parent for each node
        unordered_map<TreeNode*, bool> visited;  // To track visited nodes
        queue<TreeNode*> queue;  // BFS queue
        queue.push(target);
        visited[target] = true;
        int curr = 0;
        // Perform BFS to track nodes level by level
        while (!queue.empty()) {
            int size = queue.size();
            // Collect nodes at the k-th level
            if (curr == k) {
                vector<int> result;
                while (!queue.empty()) {
                    TreeNode* current = queue.front();
                    queue.pop();
                    result.push_back(current->val);
                }
                return result;  // Return as soon as we have all nodes at distance k
            }
            for (int i = 0; i < size; ++i) {
                TreeNode* current = queue.front();
                queue.pop();
                // Visit the left child if it's not visited
                if (current->left && !visited[current->left]) {
                    visited[current->left] = true;
                    queue.push(current->left);
                }
                // Visit the right child if it's not visited
                if (current->right && !visited[current->right]) {
                    visited[current->right] = true;
                    queue.push(current->right);
                }
                // Visit the parent if it's not visited
                if (parentTrack.find(current) != parentTrack.end() && !visited[parentTrack[current]]) {
                    visited[parentTrack[current]] = true;
                    queue.push(parentTrack[current]);
                }
            }
            curr++;  // Move to the next distance level (distance + 1)
        }
        return {};  // In case there's no node at distance k (e.g., k is too large)
    }
};
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    Solution solution;
    TreeNode* target = root->left;  // Let's say the target node is 5.
    int k = 2;
    vector<int> result = solution.distanceK(root, target, k);
    // Output result
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}