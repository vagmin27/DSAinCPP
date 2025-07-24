#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};
void inorder(TreeNode<int>* root, vector<int>& in) {
    if(root == NULL) {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root) {
    if(root == NULL) {
        return NULL;
    }
    vector<int> inorderVal;
    // Store inorder traversal values
    inorder(root, inorderVal);
    int n = inorderVal.size();
    // Create new root node for flattened tree
    TreeNode<int>* newRoot = new TreeNode<int>(inorderVal[0]);
    TreeNode<int>* curr = newRoot;
    // Create the rest of the tree using the inorder values
    for(int i = 1; i < n; i++) {
        TreeNode<int>* temp = new TreeNode<int>(inorderVal[i]);
        curr->right = temp;
        curr->left = NULL;  // Ensure the left child is null
        curr = temp;
    }
    return newRoot;
}
int main() {
    // Sample tree construction:
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->right = new TreeNode<int>(6);
    TreeNode<int>* flattened = flatten(root);
    // Output the flattened tree (linked list)
    TreeNode<int>* temp = flattened;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
    return 0;
}
