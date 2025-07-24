#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node {
    int data;
    Node* left, * right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

vector<int> diagonal(Node *root) {
    if (!root) return {};

    // Map to store nodes at each diagonal level
    map<int, vector<int>> diagonals;

    // Queue to store the node along with its diagonal level
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        Node* current = front.first;
        int level = front.second;

        // Add the current node's data to the appropriate diagonal level
        diagonals[level].push_back(current->data);

        // If there's a right child, it stays in the same diagonal level
        if (current->right) {
            q.push({current->right, level});
        }

        // If there's a left child, it moves to the next diagonal level
        if (current->left) {
            q.push({current->left, level + 1});
        }
    }

    // Flatten the map into a single result vector
    vector<int> result;
    for (auto& diagonal : diagonals) {
        result.insert(result.end(), diagonal.second.begin(), diagonal.second.end());
    }

    return result;
}

// Example usage
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    
    vector<int> result = diagonal(root);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
