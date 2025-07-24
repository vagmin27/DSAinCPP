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
Node* BuildTree(Node* root) {
    cout << "Enter the data: ";
    int data;
    cin >> data;
    // If data is -1, then return NULL (no node)
    if (data == -1) {
        return NULL;
    }
    // Create the root node
    root = new Node(data);
    // Recursively build the left and right subtrees
    cout << "Enter the left data for " << data << ": ";
    root->left = BuildTree(root->left);
    cout << "Enter the right data for " << data << ": ";
    root->right = BuildTree(root->right);
    return root;
}
void LevelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;  // If the tree is empty, do nothing
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);  // Marker for the end of a level
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);  // Add a NULL marker for the next level
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}
void buildFromLevelOrder(Node* root){
    queue<Node*>q;
    cout<<"Enter data for root "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<"Enter left node for "<<root->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new Node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for "<<root->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new Node(rightData);
            q.push(temp->right);
        }
    }
}
int main() {
    Node* root = NULL;
    // Building the tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = BuildTree(root);
    cout << "Level-order traversal: " << endl;
    LevelOrderTraversal(root);
    buildFromLevelOrder(root);
    return 0;
}