#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node *links[27] = {nullptr}; // Initialize all pointers to nullptr
    bool isLeaf = false;

    bool containsKey(char ch) {
        if (ch == '/') {
            return links[26] != nullptr;
        }
        return links[ch - 'a'] != nullptr;
    }
    Node* get(char ch) {
        if (ch == '/') {
            return links[26];
        }
        return links[ch - 'a'];
    }
    void put(char ch, Node *node) {
        if (ch == '/') {
            links[26] = node;
        } else {
            links[ch - 'a'] = node;
        }
    }
    void setEnd() {
        isLeaf = true;
    }
    bool isEnd() {
        return isLeaf;
    }
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    bool check(string word) {
        Node *temp = root;
        for (char ch : word) {
            if (!temp->containsKey(ch)) {
                return false;
            }
            temp = temp->get(ch);
            if (temp->isEnd()) {
                return false; // Found an end, this word is a subfolder
            }
        }
        return true; // Not a subfolder
    }
    void insert(string word) {
        Node *temp = root;
        for (char ch : word) {
            if (!temp->containsKey(ch)) {
                temp->put(ch, new Node());
            }
            temp = temp->get(ch);
        }
        temp->setEnd();
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string> &folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        Trie *trie = new Trie();
        for (const string &f : folder) {
            if (trie->check(f)) {
                trie->insert(f);
                ans.push_back(f);
            }
        }
        delete trie; // Clean up
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> folders = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    vector<string> result = solution.removeSubfolders(folders);
    for (const string &folder : result) {
        cout << folder << endl;
    }
    return 0;
}