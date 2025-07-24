#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
class Solution {
public:
    // Function to return a list of nodes visible from the bottom view
    vector<int> bottomView(Node* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        map<int, int> hdNodeMap;  // map to store the bottom-most node at each horizontal distance
        queue<pair<Node*, int>> q;  // queue to store nodes along with their horizontal distances
        // Push the root node with horizontal distance 0
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            Node* frontNode = temp.first;
            int hd = temp.second;
            q.pop();
            // Update the map with the node at this horizontal distance (bottom-most node)
            hdNodeMap[hd] = frontNode->data;
            // Push left and right children with updated horizontal distances
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, hd - 1));
            }
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }
        // Extract the values from the map and push them into the result vector
        for (auto i : hdNodeMap) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
int main() {
    // Creating a sample binary tree:
    //           1
    //        /     \
    //       2       3
    //    /     \   /   \
    //   4       5 6     7
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution sol;
    vector<int> result = sol.bottomView(root);
    // Print the bottom view of the binary tree
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}