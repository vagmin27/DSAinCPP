#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Helper function to create the parent mapping and find the target node.
    Node* createParentMapping(Node* root, int target, map<Node*, Node*>& nodeToParent) {
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;  // Root has no parent
        while (!q.empty()) {
            Node* front = q.front();
            q.pop();
            // If the target node is found, save it
            if (front->data == target) {
                res = front;
            }
            // Process left child
            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            // Process right child
            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    // Function to calculate the minimum time to burn the tree
    int burnTree(Node* root, map<Node*, Node*>& nodeToParent) {
        map<Node*, bool> visited;
        queue<Node*> q;
        visited[root] = true;  // Mark the root as visited
        q.push(root);
        int ans = 0;
        // BFS to simulate burning process
        while (!q.empty()) {
            bool flag = false;
            int size = q.size();
            // Process all nodes at the current level (same time unit)
            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();
                // Process left child
                if (front->left && !visited[front->left]) {
                    flag = true;
                    visited[front->left] = true;
                    q.push(front->left);
                }
                // Process right child
                if (front->right && !visited[front->right]) {
                    flag = true;
                    visited[front->right] = true;
                    q.push(front->right);
                }
                // Process parent node
                if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = true;
                    visited[nodeToParent[front]] = true;
                    q.push(nodeToParent[front]);
                }
            }
            // If we processed any node in this round, increment time
            if (flag) {
                ans++;
            }
        }
        return ans;
    }
    // Main function to find the minimum time to burn the tree starting from the target node
    int minTime(Node* root, int target) {
        map<Node*, Node*> nodeToParent;
        // Create parent mapping and find the target node
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        if (!targetNode) return 0;  // Return 0 if the target node is not found
        // Calculate the minimum time to burn the tree starting from the target node
        return burnTree(targetNode, nodeToParent);
    }
};
int main() {
    // Construct the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int target = 5;
    Solution solution;
    cout << "Minimum time to burn the tree: " << solution.minTime(root, target) << endl;
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;

// struct Node {
//     int data;
//     Node *left, *right;
//     Node(int x) : data(x), left(NULL), right(NULL) {}
// };
// class Solution {
// public:
//     // Helper function to create the parent mapping and find the target node.
//     Node* createParentMapping(Node* root, int target, map<Node*, Node*>& nodeToParent) {
//         Node* res = NULL;
//         queue<Node*> q;
//         q.push(root);
//         nodeToParent[root] = NULL;  // Root has no parent
//         while (!q.empty()) {
//             Node* front = q.front();
//             q.pop();
//             // If the target node is found, save it
//             if (front->data == target) {
//                 res = front;
//             }
//             // Process left child
//             if (front->left) {
//                 nodeToParent[front->left] = front;
//                 q.push(front->left);
//             }
//             // Process right child
//             if (front->right) {
//                 nodeToParent[front->right] = front;
//                 q.push(front->right);
//             }
//         }
//         return res;
//     }
//     // Function to calculate the minimum time to burn the tree
//     int burnTree(Node* root, map<Node*, Node*>& nodeToParent) {
//         map<Node*, bool> visited;
//         queue<Node*> q;
//         visited[root] = true;  // Mark the root as visited
//         q.push(root);
//         int ans = 0;
//         // BFS to simulate burning process
//         while (!q.empty()) {
//             bool flag = false;
//             int size = q.size();
//             // Process all nodes at the current level (same time unit)
//             for (int i = 0; i < size; i++) {
//                 Node* front = q.front();
//                 q.pop();
//                 // Process left child
//                 if (front->left && !visited[front->left]) {
//                     flag = true;
//                     visited[front->left] = true;
//                     q.push(front->left);
//                 }
//                 // Process right child
//                 if (front->right && !visited[front->right]) {
//                     flag = true;
//                     visited[front->right] = true;
//                     q.push(front->right);
//                 }
//                 // Process parent node
//                 if (nodeToParent[front] && !visited[nodeToParent[front]]) {
//                     flag = true;
//                     visited[nodeToParent[front]] = true;
//                     q.push(nodeToParent[front]);
//                 }
//             }
//             // If we processed any node in this round, increment time
//             if (flag) {
//                 ans++;
//             }
//         }
//         return ans;
//     }
//     // Main function to find the minimum time to burn the tree starting from the target node
//     int minTime(Node* root, int target) {
//         map<Node*, Node*> nodeToParent;
//         // Create parent mapping and find the target node
//         Node* targetNode = createParentMapping(root, target, nodeToParent);
//         // Calculate the minimum time to burn the tree starting from the target node
//         return burnTree(targetNode, nodeToParent);
//     }
// };
// // Helper function to create a binary tree for testing
// Node* createSampleTree() {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->right = new Node(6);
//     return root;
// }
// int main() {
//     Solution solution;
//     // Create a sample tree:
//     //        1
//     //       / \
//     //      2   3
//     //     / \   \
//     //    4   5   6
//     Node* root = createSampleTree();
//     int target = 5; // Example target to start burning
//     int result = solution.minTime(root, target);
//     cout << "Minimum time to burn the tree starting from target node " << target << ": " << result << " units." << endl;
//     return 0;
// }