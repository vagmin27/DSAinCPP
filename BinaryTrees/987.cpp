#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mp;
        queue<pair<pair<int, int>, TreeNode*>> q;
        // Initial push of the root node with (horizontal distance = 0, level = 0)
        q.push(make_pair(make_pair(0, 0), root));
        // Perform BFS traversal
        while (!q.empty()) {
            int size = q.size();  // Number of nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front().second;
                int level = q.front().first.second;
                int dis = q.front().first.first;
                // Insert the node value into the map at the correct (dis, level)
                mp[dis][level].insert(front->val);
                // Pop the front element from the queue
                q.pop();
                // If there is a left child, add it to the queue with updated horizontal distance and level
                if (front->left) 
                    q.push(make_pair(make_pair(dis - 1, level + 1), front->left));
                // If there is a right child, add it to the queue with updated horizontal distance and level
                if (front->right)
                    q.push(make_pair(make_pair(dis + 1, level + 1), front->right));
            }
        }
        // Construct the final result from the map 'mp'
        for (auto i : mp) {
            vector<int> temp;  // To store the vertical order for this particular horizontal distance
            // For each level at this horizontal distance, add all the node values in sorted order (since we are using multiset)
            for (auto j : i.second) {
                for (auto k : j.second)
                    temp.push_back(k);
            }
            // Add this vertical order to the result
            ans.push_back(temp);
        }
        return ans;  // Return the final vertical order traversal
    }
};
// Test the solution
int main() {
    // Construct a binary tree for testing: Example
    //        3
    //       / \
    //      9  20
    //         /  \
    //        15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    // Create the solution object and call the verticalTraversal function
    Solution solution;
    vector<vector<int>> result = solution.verticalTraversal(root);
    // Print the result
    for (const auto& column : result) {
        for (int val : column) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

// #include <iostream>
// #include <map>
// #include <queue>
// #include <vector>
// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     Node(int x) : data(x), left(NULL), right(NULL) {}
// };

// class Solution {
// public:
//     // Function to find the vertical order traversal of Binary Tree.
//     vector<int> verticalOrder(Node *root) {
//         vector<int> ans;
//         if (root == NULL) {
//             return ans;
//         }
//         // Map to store vertical order {horizontal_distance -> {level -> list of node values}}
//         map<int, map<int, vector<int>>> nodes;
//         queue<pair<Node*, pair<int, int>>> q;
//         // Start with the root node, at horizontal distance 0 and level 0
//         q.push({root, {0, 0}});
//         while (!q.empty()) {
//             auto temp = q.front();
//             q.pop();
//             Node* frontNode = temp.first;
//             int hd = temp.second.first;
//             int lvl = temp.second.second;
//             // Add current node data to the map
//             nodes[hd][lvl].push_back(frontNode->data);
//             // Push left child with updated horizontal distance and level
//             if (frontNode->left) {
//                 q.push({frontNode->left, {hd - 1, lvl + 1}});
//             }
//             // Push right child with updated horizontal distance and level
//             if (frontNode->right) {
//                 q.push({frontNode->right, {hd + 1, lvl + 1}});
//             }
//         }
//         // Construct the final vertical order
//         for (auto& i : nodes) {
//             for (auto& j : i.second) {
//                 for (auto& k : j.second) {
//                     ans.push_back(k);
//                 }
//             }
//         }
//         return ans;
//     }
// };

// int main() {
//     // Constructing the binary tree
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->right->left = new Node(5);
//     root->right->right = new Node(6);
//     Solution sol;
//     vector<int> result = sol.verticalOrder(root);
//     // Printing the vertical order traversal
//     for (int val : result) {
//         cout << val << " ";
//     }
    
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <set>
// #include <queue>
// #include <map>
// using namespace std;

// // Node structure for the binary tree
// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     // Constructor to initialize
//     // the node with a value
//     Node(int val) : data(val), left(nullptr), right(nullptr) {}
// };
// class Solution {
// public:
//     // Function to perform vertical order traversal
//     // and return a 2D vector of node values
//     vector<vector<int>> findVertical(Node* root){
//         // Map to store nodes based on
//         // vertical and level information
//         map<int, map<int, multiset<int>>> nodes;
//         // Queue for BFS traversal, each
//         // element is a pair containing node
//         // and its vertical and level information
//         queue<pair<Node*, pair<int, int>>> todo;
//         // Push the root node with initial vertical
//         // and level values (0, 0)
//         todo.push({root, {0, 0}});
//         // BFS traversal
//         while(!todo.empty()){
//             // Retrieve the node and its vertical
//             // and level information from
//             // the front of the queue
//             auto p = todo.front();
//             todo.pop();
//             Node* temp = p.first;
//             // Extract the vertical and level information
//             // x -> vertical
//             int x = p.second.first;
//             // y -> level
//             int y = p.second.second;
//             // Insert the node value into the
//             // corresponding vertical and level
//             // in the map
//             nodes[x][y].insert(temp->data);
//             // Process left child
//             if(temp->left){
//                 todo.push({
//                     temp->left,
//                     {
//                         // Move left in
//                         // terms of vertical
//                         x-1,
//                         // Move down in
//                         // terms of level
//                         y+1
//                     }
//                 });
//             }
//             // Process right child
//             if(temp->right){
//                 todo.push({
//                     temp->right,
//                     {
//                         // Move right in
//                         // terms of vertical
//                         x+1,
//                         // Move down in
//                         // terms of level
//                         y+1
//                     }
//                 });
//             }
//         }
//         // Prepare the final result vector
//         // by combining values from the map
//         vector<vector<int>> ans;
//         for(auto p: nodes){
//             vector<int> col;
//             for(auto q: p.second){
//                 // Insert node values
//                 // into the column vector
//                 col.insert(col.end(), q.second.begin(), q.second.end());
//             }
//             // Add the column vector
//             // to the final result
//             ans.push_back(col);
//         }
//         return ans;
//     }
// };
// // Helper function to
// // print the result
// void printResult(const vector<vector<int>>& result) {
//     for(auto level: result){
//         for(auto node: level){
//             cout << node << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }
// int main() {
//     // Creating a sample binary tree
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->left->left = new Node(4);
//     root->left->right = new Node(10);
//     root->left->left->right = new Node(5);
//     root->left->left->right->right = new Node(6);
//     root->right = new Node(3);
//     root->right->right = new Node(10);
//     root->right->left = new Node(9);
//     Solution solution;
//     // Get the Vertical traversal
//     vector<vector<int>> verticalTraversal =solution.findVertical(root);
//     // Print the result
//     cout << "Vertical Traversal: ";
//     printResult(verticalTraversal);
//     return 0;
// }