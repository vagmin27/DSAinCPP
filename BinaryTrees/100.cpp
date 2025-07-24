#include <bits/stdc++.h>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: if both nodes are NULL, the trees are the same
        if (p == NULL && q == NULL) {
            return true;
        }
        // If one of the nodes is NULL and the other is not, trees are not the same
        if (p == NULL || q == NULL) {
            return false;
        }
        // Check if current node values are the same and recursively check left and right subtrees
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
int main() {
    // Creating two test trees
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);
    tree1->left->left = new TreeNode(4);
    tree1->left->right = new TreeNode(5);
    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);
    tree2->left->left = new TreeNode(4);
    tree2->left->right = new TreeNode(5);
    // Create a solution object and test the trees
    Solution solution;
    if (solution.isSameTree(tree1, tree2)) {
        cout << "The two trees are the same." << endl;
    }
    else {
        cout << "The two trees are NOT the same." << endl;
    }
    // Clean up dynamically allocated memory
    delete tree1->left->left;
    delete tree1->left->right;
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left->left;
    delete tree2->left->right;
    delete tree2->left;
    delete tree2->right;
    delete tree2;
    return 0;
}