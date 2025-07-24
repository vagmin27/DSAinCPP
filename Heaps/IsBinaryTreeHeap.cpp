#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
class Solution {
    private:
    int countNodes(struct Node* root) {
        // Base case
        if (root == NULL) {
            return 0;
        }
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }
    bool isCBT(struct Node* root, int i, int count) {
        if (root == NULL) {
            return true;
        }
        if (i >= count) {
            return false;
        }
        bool left = isCBT(root->left, 2*i + 1, count); // Left child index
        bool right = isCBT(root->right, 2*i + 2, count); // Right child index
        return (left && right);
    }
    bool isMaxOrder(struct Node* root) {
        // Leaf Node (No children, trivially satisfies max-heap)
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        // Only left child (right is NULL)
        if (root->right == NULL) {
            return (root->data > root->left->data);
        }
        // Both children exist
        else {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            return (left && right && root->data > root->left->data && root->data > root->right->data);
        }
    }
    public:
    bool isHeap(struct Node* tree) {
        int totalCount = countNodes(tree);
        return isCBT(tree, 0, totalCount) && isMaxOrder(tree);
    }
};
int main() {
    // Create a simple tree (for example, a valid Max Heap)
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    Solution sol;
    if (sol.isHeap(root)) {
        cout << "The tree is a Max Heap and a Complete Binary Tree." << endl;
    } else {
        cout << "The tree is not a Max Heap or not a Complete Binary Tree." << endl;
    }
    return 0;
}