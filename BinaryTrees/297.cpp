#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            if (currNode == NULL) {
                s.append("null,");
            } else {
                s.append(to_string(currNode->val) + ",");
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        // Remove the trailing comma
        s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }
        stringstream ss(data);
        string str;
        getline(ss, str, ','); // Read the first value for the root
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            // Read the left child
            if (getline(ss, str, ',')) {
                if (str == "null") {
                    node->left = NULL;
                }
                else {
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }
            // Read the right child
            if (getline(ss, str, ',')) {
                if (str == "null") {
                    node->right = NULL;
                } else {
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        return root;
    }
};

int main() {
    Codec codec;
    // Test case 1: Create a simple binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    // Serialize the tree
    string serialized = codec.serialize(root);
    cout << "Serialized Tree: " << serialized << endl;
    // Deserialize the tree
    TreeNode* deserializedRoot = codec.deserialize(serialized);
    cout << "Deserialized Root Value: " << deserializedRoot->val << endl;
    return 0;
}