#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* BuildTree() {
    cout << "Enter node data (-1 for NULL): ";
    int data;
    cin >> data;
    if (data == -1) return NULL;  // return NULL if data is -1
    Node* root = new Node(data);  // create a new node with the given data
    // Recursively build the left and right subtrees
    cout << "Enter the left child of " << data << ": " << endl;
    root->left = BuildTree();
    cout << "Enter the right child of " << data << ": " << endl;
    root->right = BuildTree();
    return root;
}
// Inorder Traversal (LNR)
void inorder(Node* root) {
    if (root == NULL) return;  // base case
    inorder(root->left);  // traverse left subtree
    cout << root->data << " ";  // visit the node
    inorder(root->right);  // traverse right subtree
}
// Preorder Traversal (NLR)
void preorder(Node* root) {
    if (root == NULL) return;  // base case
    cout << root->data << " ";  // visit the node
    preorder(root->left);  // traverse left subtree
    preorder(root->right);  // traverse right subtree
}
// Postorder Traversal (LRN)
void postorder(Node* root) {
    if (root == NULL) return;  // base case
    postorder(root->left);  // traverse left subtree
    postorder(root->right);  // traverse right subtree
    cout << root->data << " ";  // visit the node
}
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if (root == NULL) {
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> v;
        int l = q.size();
        for (int i = 0; i < l; i++) {
            Node* st = q.front();
            q.pop();
            if (st->left != NULL) {
                q.push(st->left);
            }
            if (st->right != NULL) {
                q.push(st->right);
            }
            v.push_back(st->data);
        }
        ans.push_back(v);
    }
    return ans;
}
int minValue(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}
int maxValue(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}
Node* insertIntoBST(Node* &root, int d) {
    if (root == NULL) {
        return new Node(d); // return new node if root is null
    }
    if (d > root->data) {
        // insertion in the right subtree
        root->right = insertIntoBST(root->right, d);
    }
    else {
        // insertion in the left subtree
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}
void takeInput(Node* &root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}
int main() {
    Node* root = NULL;
    cout << "Enter the data to create a Binary Search Tree (-1 to stop): " << endl;
    takeInput(root);
    cout << "Level-order traversal of the BST:" << endl;
    vector<vector<int>> levelOrderResult = levelOrder(root);
    // Print the level-order traversal
    for (const auto& level : levelOrderResult) {
        for (int value : level) {
            cout << value << " ";
        }
        cout << endl;
    }
    cout<<"Printing Inorder"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Printing Preorder"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Printing Postorder"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Minimum Value : "<<minValue(root)<<endl;
    cout<<"Maximum Value : "<<maxValue(root)<<endl;
    return 0;
}