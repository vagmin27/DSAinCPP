#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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
    // Preorder traversal (root, left, right)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == NULL) return v;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            v.push_back(root->val);
            if (root->right != NULL) {
                s.push(root->right);
            }
            if (root->left != NULL) {
                s.push(root->left);
            }
        }
        return v;
    }

    // Inorder traversal (left, root, right)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        TreeNode* node = root;
        while (true) {
            if (node != NULL) {
                stack.push(node);
                node = node->left;  // Go to the left subtree
            }
            else {
                if (stack.empty()) {
                    break;  // When stack is empty, we are done
                }
                node = stack.top();  // Get the node to process
                stack.pop();  // Pop the node from stack
                result.push_back(node->val);  // Process the node
                node = node->right;  // Move to the right subtree
            }
        }
        return result;
    }

    // Postorder traversal (left, right, root)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode*> s1;
        stack<int> s2;
        s1.push(root);
        while (!s1.empty()) {
            TreeNode* temp = s1.top();
            s1.pop();
            s2.push(temp->val);
            // Push left and right children into s1
            if (temp->left != nullptr) {
                s1.push(temp->left);
            }
            if (temp->right != nullptr) {
                s1.push(temp->right);
            }
        }
        // Pop values from s2 to get the postorder sequence
        while (!s2.empty()) {
            res.push_back(s2.top());
            s2.pop();
        }
        return res;
    }
};

int main() {
    // Create a simple binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution solution;
    // Example usage for tree traversal
    vector<int> result = solution.postorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    vector<int> v = solution.preorderTraversal(root);
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;
    vector<int> v1 = solution.inorderTraversal(root);
    for (int val : v1) {
        cout << val << " ";
    }
    cout << endl;
    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}