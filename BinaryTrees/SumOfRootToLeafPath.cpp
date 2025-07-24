#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
private:
    void solve(Node* root, int currentSum, int currentLen, int& maxSum, int& maxLen) {
        if (root == NULL) return;

        // Update the current sum and length
        currentSum += root->data;
        currentLen++;

        // If it's a leaf node, we check if we should update the result
        if (root->left == NULL && root->right == NULL) {
            if (currentLen > maxLen) {
                maxLen = currentLen;
                maxSum = currentSum;
            } else if (currentLen == maxLen) {
                maxSum = max(maxSum, currentSum);
            }
        }

        // Recur for left and right subtrees
        solve(root->left, currentSum, currentLen, maxSum, maxLen);
        solve(root->right, currentSum, currentLen, maxSum, maxLen);
    }

public:
    int sumOfLongRootToLeafPath(Node* root) {
        if (root == NULL) return 0;

        int maxLen = 0;
        int maxSum = 0;
        solve(root, 0, 0, maxSum, maxLen);
        return maxSum;
    }
};

int main() {
    // Example tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution solution;
    cout << "Sum of the longest path: " << solution.sumOfLongRootToLeafPath(root) << endl;

    return 0;
}