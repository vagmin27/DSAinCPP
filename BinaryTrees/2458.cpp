#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> depth;
        unordered_map<int, int> height;
        unordered_map<int, vector<int>> maxDepthHeights;
        
        function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int d) {
            if (!node) return -1;
            depth[node->val] = d;
            int leftHeight = dfs(node->left, d + 1);
            int rightHeight = dfs(node->right, d + 1);
            int nodeHeight = 1 + max(leftHeight, rightHeight);
            height[node->val] = nodeHeight;
            maxDepthHeights[d].push_back(nodeHeight);
            return nodeHeight;
        };
        
        dfs(root, 0);
        
        unordered_map<int, vector<int>> maxHeightByDepth;
        for (const auto& pair : maxDepthHeights) {
            vector<int> heights = pair.second;
            sort(heights.rbegin(), heights.rend());
            maxHeightByDepth[pair.first] = {heights[0], heights.size() > 1 ? heights[1] : 0};
        }
        
        vector<int> result;
        for (int q : queries) {
            int nodeDepth = depth[q];
            int nodeHeight = height[q];
            if (maxHeightByDepth[nodeDepth].size() == 1) {
                result.push_back(nodeDepth - 1);
            } else if (maxHeightByDepth[nodeDepth][0] == nodeHeight) {
                result.push_back(maxHeightByDepth[nodeDepth][1] + nodeDepth);
            } else {
                result.push_back(maxHeightByDepth[nodeDepth][0] + nodeDepth);
            }
        }
        
        return result; 
    }
};

int main() {
    // Construct a binary tree for testing
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    vector<int> queries = {1, 2, 3, 4, 5};
    
    Solution solution;
    vector<int> results = solution.treeQueries(root, queries);
    
    // Print the results
    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;

    // Cleanup the tree (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}