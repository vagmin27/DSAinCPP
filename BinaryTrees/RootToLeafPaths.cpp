#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    // Helper function to perform DFS
    void dfs(Node* root, vector<int>& currentPath, vector<vector<int>>& result) {
        // Base case: if the node is NULL, return
        if (!root) {
            return;
        }
        // Add the current node's value to the path
        currentPath.push_back(root->data);
        // If it's a leaf node, add the current path to the result
        if (!root->left && !root->right) {
            result.push_back(currentPath);
        }
        else {
            // Recursively visit the left and right subtrees
            dfs(root->left, currentPath, result);
            dfs(root->right, currentPath, result);
        }
        // Backtrack: remove the current node's value from the path
        currentPath.pop_back();
    }
    // Main function to find all paths from root to leaf
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> currentPath;
        // Start the DFS traversal
        dfs(root, currentPath, result);
        return result;
    }
};

int main() {
    // Construct a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // Create an object of Solution
    Solution solution;
    // Get all paths from root to leaf
    vector<vector<int>> paths = solution.Paths(root);
    // Print the paths
    cout << "Paths from root to leaf:" << endl;
    for (const auto& path : paths) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    // Free the allocated memory (not required for small programs but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}