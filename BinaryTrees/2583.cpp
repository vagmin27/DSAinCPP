#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// class Solution {
// public:
//     long long kthLargestLevelSum(TreeNode* root, int k) {
//         vector<long long> res;// To store sum of each level
//         queue<TreeNode*> q;// Queue for level-order traversal (BFS)
//         if (!root) return -1;// If the tree is empty
//         q.push(root);// Start BFS from the root node
//         while (!q.empty()) {
//             int n = q.size();// Number of nodes at the current level
//             long long sum = 0;// Sum of node values at the current level
//             // Process all nodes at the current level
//             while (n--) {
//                 TreeNode* node = q.front(); q.pop();// Get the front node from the queue
//                 sum += (long long)node->val;// Add node's value to the level sum
//                 // Push left and right children of the node to the queue (if they exist)
//                 if (node->left) q.push(node->left);
//                 if (node->right) q.push(node->right);
//             }
//             res.push_back(sum);// Store the sum of the current level
//         }
//         // If k is greater than the number of levels, return -1
//         if (k > res.size()) return -1;
//         // Sort the level sums in descending order
//         sort(res.begin(), res.end(), greater<long long>());
//         // Return the k-th largest level sum (k-1 due to 0-based indexing)
//         return res[k - 1];
//     }
// };
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Min-heap to store the k largest level sums
        priority_queue<long long ,vector<long long>,greater<long long>> pq;
        long long levelSum = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);  // Use NULL as a marker for end of the level
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node != NULL) {
                // Add the current node's value to the level sum
                levelSum += node->val;
                // Add child nodes to the queue for the next level
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            else {
                // If we reach the end of the level (NULL marker)
                if(pq.size() < k) {
                    pq.push(levelSum);  // Push the level sum if heap is not full
                } else if(levelSum > pq.top()) {
                    pq.pop();  // Remove the smallest sum in the heap
                    pq.push(levelSum);  // Add the current level sum
                }
                // Reset level sum for the next level
                levelSum = 0;
                // If there are more levels, add a new NULL marker
                if(!q.empty()) q.push(NULL);
            }
        }
        // If there are fewer than k levels, return -1
        if(pq.size() < k) return -1;
        return pq.top();  // The k-th largest level sum
    }
};
TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}
int main() {
    Solution solution;
    TreeNode* root = createTree();
    int k = 2;
    long long result = solution.kthLargestLevelSum(root, k);
    cout << "The " << k << "th largest level sum is: " << result << endl;
    return 0;
}