#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, const string& word, int index) {
        if (index == word.length()) {
            root->isTerminal = true;
            return;
        }
        int charIndex = word[index] - 'a';
        TrieNode* child;
        if (root->children[charIndex] != NULL) {
            child = root->children[charIndex];
        }
        else {
            child = new TrieNode(word[index]);
            root->children[charIndex] = child;
            root->childCount++;
        }
        insertUtil(child, word, index + 1);
    }

    void insert(const string& word) {
        insertUtil(root, word, 0);
    }
    void lcp(string str, string& ans) {
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if (root->childCount == 1) {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            else {
                break;
            }
            if (root->isTerminal) break;
        }
    }
};
string longestCommonPrefix(vector<string>& arr, int n) {
    Trie* t = new Trie();
    for (int i = 0; i < n; i++) {
        t->insert(arr[i]);
    }
    string first = arr[0];
    string ans = "";
    t->lcp(first, ans);
    return ans;
}
int main() {
    vector<string> arr = {"flower", "flow", "flight"};
    int n = arr.size();
    cout << "Longest Common Prefix: " << longestCommonPrefix(arr, n) << endl;
    return 0;
}