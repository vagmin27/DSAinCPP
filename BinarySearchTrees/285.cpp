#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};
pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    TreeNode* temp = root;
    int pred = -1, succ = -1;
    while (temp != NULL) {
        if (temp->data > key) {
            succ = temp->data;
            temp = temp->left;
        } else if (temp->data < key) {
            pred = temp->data;
            temp = temp->right;
        } else {
            if (temp->left != NULL) {
                TreeNode* leftTree = temp->left;
                while (leftTree->right != NULL) {
                    leftTree = leftTree->right;
                }
                pred = leftTree->data;
            }
            if (temp->right != NULL) {
                TreeNode* rightTree = temp->right;
                while (rightTree->left != NULL) {
                    rightTree = rightTree->left;
                }
                succ = rightTree->data;
            }
            break;
        }
    }
    return {pred, succ};
}

int main() {
    // Create a simple binary search tree
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);
    int key = 15;
    pair<int, int> result = predecessorSuccessor(root, key);
    cout << "Predecessor: " << result.first << endl;
    cout << "Successor: " << result.second << endl;
    return 0;
}