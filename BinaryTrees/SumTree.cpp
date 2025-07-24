#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left, * right;
    
    Node(int x) : data(x), left(nullptr), right(nullptr) {} // Constructor to initialize node
};

class Solution {
private:
    pair<bool, int> isSumTreeFast(Node* root) {
        // Base case: an empty tree or a leaf node
        if (root == NULL) {
            return {true, 0}; // An empty tree is a Sum Tree with sum 0
        }
        if (root->left == NULL && root->right == NULL) {
            return {true, root->data}; // Leaf node, its sum is its own value
        }
        // Recur for left and right subtrees
        pair<bool, int> leftAns = isSumTreeFast(root->left);
        pair<bool, int> rightAns = isSumTreeFast(root->right);
        // If either left or right subtree is not a Sum Tree, return false
        if (!leftAns.first || !rightAns.first) {
            return {false, 0};
        }
        // The current node's value should be the sum of the left and right subtree sums
        int currentSum = leftAns.second + rightAns.second;
        // Check if current node satisfies the Sum Tree property
        bool isSumTree = (root->data == currentSum);
        // The total sum for this subtree rooted at 'root' is its value plus the sums of its left and right subtrees
        int totalSum = currentSum + root->data;
        // Return whether the tree is a Sum Tree and the total sum of this subtree
        return {isSumTree, totalSum};
    }
public:
    bool isSumTree(Node* root) {
        return isSumTreeFast(root).first;
    }
};
int main() {
    // Create a tree
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);
    // Create a solution object
    Solution sol;
    // Check if the tree is a sum tree
    if (sol.isSumTree(root)) {
        cout << "The tree is a Sum Tree." << endl;
    }
    else {
        cout << "The tree is NOT a Sum Tree." << endl;
    }
    return 0;
}