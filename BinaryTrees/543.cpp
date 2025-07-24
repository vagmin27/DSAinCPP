#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// class Solution {
// public:
// int maxDepth(TreeNode* root) {
//         if(root==NULL){
//             return 0;
//         }
//         int left=maxDepth(root->left);
//         int right=maxDepth(root->right);
//         int ans=max(left,right)+1;
//         return ans;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==NULL){
//             return 0;
//         }
//         int opt1=diameterOfBinaryTree(root->left);
//         int opt2=diameterOfBinaryTree(root->right);
//         int opt3=maxDepth(root->left)+maxDepth(root->right);
//         int ans=max(opt1,max(opt2,opt3));
//         return ans;
//     }
// };

// class Solution {
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         int diameter = 0;
//         height(root, diameter);
//         return diameter;
//     }
//     int height(TreeNode* root, int& diameter) {
//         if (root == nullptr) {
//             return 0;
//         }
//         int left = height(root->left, diameter);
//         int right = height(root->right, diameter);
//         diameter = max(diameter, left + right);
//         return max(left, right) + 1;
//     }
// };
class Solution {
public:
    pair<int, int> diameterFast(TreeNode* root) {
        if (root == NULL) {
            return make_pair(0, 0); // diameter, depth
        }
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);
        int opt1 = left.first; // diameter in the left subtree
        int opt2 = right.first; // diameter in the right subtree
        int opt3 = left.second + right.second + 1; // diameter through the current root
        return make_pair(max(opt1, max(opt2, opt3)), max(left.second, right.second) + 1); // diameter, depth
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first; // Return the diameter
    }
};
// Main function to test the solution
int main() {
    // Create a binary tree for testing
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    // Create a Solution object
    Solution solution;
    // Calculate the diameter of the binary tree
    int diameter = solution.diameterOfBinaryTree(root);
    // Print the result
    cout << "Diameter of the binary tree is: " << diameter << endl;
    // Clean up the allocated memory (optional but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}