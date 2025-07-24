#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    void solve(TreeNode *root, map<TreeNode*, TreeNode*> &mp) {
        if (root == NULL) {
            return;
        }
        if (root->left) mp[root->left] = root;
        if (root->right) mp[root->right] = root;
        solve(root->left, mp);
        solve(root->right, mp);
    }
    void accvalue(TreeNode *root, unordered_map<TreeNode*, int> &mp) {
        if (root == NULL) return;
        mp[root] = root->val;
        accvalue(root->left, mp);
        accvalue(root->right, mp);
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == NULL) return NULL;
        map<TreeNode*, TreeNode*> mp;
        solve(root, mp);
        mp[root] = NULL;
        unordered_map<TreeNode*, int> m;
        accvalue(root, m);
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty()) {
            int n = q.size();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode *currnode = q.front();
                q.pop();
                sum += currnode->val;
                if (currnode->left) q.push(currnode->left);
                if (currnode->right) q.push(currnode->right);
            }
            ans.push_back(sum);
        }
        queue<TreeNode*> pq;
        pq.push(root);
        int ptr = 0;
        while (!pq.empty()) {
            int n = pq.size();
            int levelsum = ans[ptr++];
            for (int i = 0; i < n; i++) {
                TreeNode *currnode = pq.front();
                pq.pop();
                TreeNode *par = mp[currnode];
                if (par == NULL) {
                    currnode->val = 0;
                } else if (par->left == currnode) {
                    if (par->right) currnode->val = levelsum - currnode->val - m[par->right];
                    else currnode->val = levelsum - currnode->val;
                } else if (par->right == currnode) {
                    if (par->left) currnode->val = levelsum - currnode->val - m[par->left];
                    else currnode->val = levelsum - currnode->val;
                }
                if (currnode->left) pq.push(currnode->left);
                if (currnode->right) pq.push(currnode->right);
            }
        }
        return root;
    }
};//T.C O(N),S.C O(N).

// class Solution {
// public:
//     int getNodeSum(TreeNode* root) {
//         int left;
//         int right;
//         if (root->left) {
//             left = root->left->val;
//         } else {
//             left = 0;
//         }
//         if (root->right) {
//             right = root->right->val;
//         }
//         else{
//             right = 0;
//         }
//         return left + right;
// }
//     TreeNode* replaceValueInTree(TreeNode* root) {
//         queue<TreeNode*> q;
//         root->val = 0;
//         q.push(root);
//         int currSum = getNodeSum(root);
//         while (!q.empty()) {
//             int size = q.size();
//             int levelSum = 0;
//             for (; size > 0; size--) {
//                 auto temp = q.front();
//                 q.pop();
//                 int calculatedSum = currSum - getNodeSum(temp);
//                 if (temp->left) {
//                     levelSum += getNodeSum(temp->left);
//                     q.push(temp->left);
//                     temp->left->val = max(calculatedSum, 0);
//                 }
//                 if (temp->right) {
//                     levelSum += getNodeSum(temp->right);
//                     q.push(temp->right);
//                     temp->right->val = max(calculatedSum, 0);
//                 }
//             }
//             currSum = levelSum;
//         }
//         return root;
//     }
// };

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    Solution sol;
    TreeNode* newRoot = sol.replaceValueInTree(root);
    auto printLevelOrder = [](TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    };
    printLevelOrder(newRoot);
    return 0;
}