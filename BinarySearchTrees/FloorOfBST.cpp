#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class Solution {
public:
    int floor(Node* root, int x) {
        // Base case: If the root is NULL, return -1 (no floor found)
        if (root == NULL) {
            return -1;
        }
        // If the root data matches x, then return the value as the floor
        if (root->data == x) {
            return x;
        }
        // If root's data is greater than x, the floor must be in the left subtree
        if (root->data > x) {
            return floor(root->left, x);
        }
        // If root's data is less than x, check the right subtree for a better floor
        int rightFloor = floor(root->right, x);
        // If the right subtree does not have any value <= x, return the current node's data
        if (rightFloor == -1) {
            return root->data;
        }
        // Otherwise, return the floor value found in the right subtree
        return rightFloor;
    }
};

int main() {
    // Create a simple binary search tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->right->left = new Node(15);
    root->right->right = new Node(25);
    // Create a Solution object
    Solution solution;
    // Test case 1: Find the floor of 12
    int x = 12;
    int result = solution.floor(root, x);
    cout << "The floor of " << x << " is: " << result << endl;
    // Test case 2: Find the floor of 6
    x = 6;
    result = solution.floor(root, x);
    cout << "The floor of " << x << " is: " << result << endl;
    // Test case 3: Find the floor of 25
    x = 25;
    result = solution.floor(root, x);
    cout << "The floor of " << x << " is: " << result << endl;
    // Test case 4: Find the floor of 30 (no value <= 30, so the floor should be 25)
    x = 30;
    result = solution.floor(root, x);
    cout << "The floor of " << x << " is: " << result << endl;
    return 0;
}