#include<bits/stdc++.h>
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
    // Function to return a list of nodes visible from the top view
    vector<int> topView(Node* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        map<int, int> topNode;  // map to store the first node at each horizontal distance
        queue<pair<Node*, int>> q;  // queue to store nodes along with their horizontal distance
        q.push(make_pair(root, 0));  // push root with horizontal distance 0
        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            Node* frontNode = temp.first;
            int hd = temp.second;
            q.pop();
            // If this horizontal distance has not been seen before, add the node to top view
            if (topNode.find(hd) == topNode.end()) {
                topNode[hd] = frontNode->data;
            }
            // Push left and right children with updated horizontal distances
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, hd - 1));
            }
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }
        // Extract the values from the map and push them into the result vector
        for (auto i : topNode) {
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
    vector<int> result = sol.topView(root);
    // Print the top view of the binary tree
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}