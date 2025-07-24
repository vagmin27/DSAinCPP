#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
// Function to build the tree
Node* BuildTree() {
    cout << "Enter node data (-1 for NULL): ";
    int data;
    cin >> data;
    if (data == -1) return NULL;  // return NULL if data is -1
    Node* root = new Node(data);  // create a new node with the given data
    // Recursively build the left and right subtrees
    cout << "Enter the left child of " << data << ": " << endl;
    root->left = BuildTree();
    cout << "Enter the right child of " << data << ": " << endl;
    root->right = BuildTree();
    return root;
}
// Inorder Traversal (LNR)
void inorder(Node* root) {
    if (root == NULL) return;  // base case
    inorder(root->left);  // traverse left subtree
    cout << root->data << " ";  // visit the node
    inorder(root->right);  // traverse right subtree
}
// Preorder Traversal (NLR)
void preorder(Node* root) {
    if (root == NULL) return;  // base case
    cout << root->data << " ";  // visit the node
    preorder(root->left);  // traverse left subtree
    preorder(root->right);  // traverse right subtree
}
// Postorder Traversal (LRN)
void postorder(Node* root) {
    if (root == NULL) return;  // base case
    postorder(root->left);  // traverse left subtree
    postorder(root->right);  // traverse right subtree
    cout << root->data << " ";  // visit the node
}
int main() {
    Node* root = NULL;
    // Build the tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Build the tree:\n";
    root = BuildTree();
    // Print tree traversals
    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << endl;
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;
    return 0;
}