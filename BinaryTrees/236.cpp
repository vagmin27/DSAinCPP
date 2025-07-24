#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==p || root==q){
            return root;
        }
        TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);
        if(leftAns!=NULL && rightAns!=NULL){
            return root;
        }
        else if(leftAns!=NULL && rightAns==NULL){
            return leftAns;
        }
        else if(leftAns==NULL && rightAns!=NULL){
            return rightAns;
        }
        else{
            return NULL;
        }
    }
};
int main() {
    // Build a simple test tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    // Initialize nodes p and q
    TreeNode* p = root->left;    // Node with value 5
    TreeNode* q = root->left->right->right;  // Node with value 4
    Solution solution;
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    if (lca != NULL) {
        cout << "The LCA of nodes " << p->val << " and " << q->val << " is " << lca->val << endl;
    }
    else {
        cout << "No common ancestor found." << endl;
    }
    return 0;
}