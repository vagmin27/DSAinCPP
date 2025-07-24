#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};
class Solution {
public:
    int getHeight(Node* root) {
        if (!root) return 0;
        return root->height;
    }
    int getBalance(Node* root) {
        return getHeight(root->left) - getHeight(root->right);
    }
    Node* rightRotation(Node* root) {
        Node* child = root->left;
        Node* rightChild = child->right;
        // Perform rotation
        child->right = root;
        root->left = rightChild;
        // Update heights
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        child->height = 1 + max(getHeight(child->left), getHeight(child->right));
        return child;
    }
    Node* leftRotation(Node* root) {
        Node* child = root->right;
        Node* leftChild = child->left;
        // Perform rotation
        child->left = root;
        root->right = leftChild;
        // Update heights
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        child->height = 1 + max(getHeight(child->left), getHeight(child->right));
        return child;
    }
    void preorder(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    Node* insert(Node* root, int key) {
        // Step 1: Perform the normal BST insertion
        if (!root){
            return new Node(key);
        }
        if (key < root->data) {
            root->left = insert(root->left, key);
        }
        else if (key > root->data) {
            root->right = insert(root->right, key);
        }
        else {
            return root;  // Duplicates are not allowed
        }
        // Step 2: Update the height of this ancestor node
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        // Step 3: Get the balance factor to check whether this node became unbalanced
        int balance = getBalance(root);
        // Left Left Case
        if (balance > 1 && key < root->left->data) {
            return rightRotation(root);
        }
        // Right Right Case
        if (balance < -1 && key > root->right->data) {
            return leftRotation(root);
        }
        // Left Right Case
        if (balance > 1 && key > root->left->data) {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
        // Right Left Case
        if (balance < -1 && key < root->right->data) {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
        // No balancing needed
        return root;
    }
};
int main() {
    Solution sol;
    Node* root = NULL;
    // Insert elements
    root = sol.insert(root, 10);
    root = sol.insert(root, 20);
    root = sol.insert(root, 30);
    root = sol.insert(root, 15);
    // Print preorder and inorder traversals
    cout << "Preorder Traversal: ";
    sol.preorder(root);
    cout << endl;
    cout << "Inorder Traversal: ";
    sol.inorder(root);
    cout << endl;
    return 0;
}