#include <bits/stdc++.h>
using namespace std; 
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int wordCount;     // Number of times the word has been inserted
    int prefixCount;   // Number of words with this prefix

    TrieNode() {
        wordCount = 0;
        prefixCount = 0;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            node->prefixCount++;
        }
        node->wordCount++;
    }
    // Search if a word exists in the Trie
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->wordCount > 0;
    }
    // Check if any word starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }
    // Count how many times the exact word has been inserted
    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return 0; // Word does not exist
            }
            node = node->children[ch];
        }
        return node->wordCount;
    }
    // Count how many words start with the given prefix
    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return 0; // No words with this prefix
            }
            node = node->children[ch];
        }
        return node->prefixCount;
    }
    // Erase a word from the Trie
    void erase(string word) {
        TrieNode* node = root;
        stack<pair<TrieNode*, char>> nodesStack; // To keep track of nodes and characters for backtracking
        // Traverse the word and collect nodes along the path
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return; // Word does not exist, nothing to erase
            }
            nodesStack.push({node, ch});
            node = node->children[ch];
        }
        // Decrease the word count at the final node
        if (node->wordCount > 0) {
            node->wordCount--;
        }
        // Backtrack and decrease prefixCount for each node
        for (int i = word.size() - 1; i >= 0; i--) {
            auto [parentNode, charToErase] = nodesStack.top();
            nodesStack.pop();
            TrieNode* currentNode = parentNode->children[charToErase];
            currentNode->prefixCount--;
            // If no words with this prefix remain and it's not a terminal node, delete it
            if (currentNode->prefixCount == 0 && currentNode->wordCount == 0) {
                parentNode->children.erase(charToErase);
                delete currentNode;
            }
        }
    }
};
int main() {
    Trie* trie = new Trie();
    trie->insert("APPLE");
    trie->insert("APP");
    cout << "Search APP: " << trie->search("APP") << endl;          // Output: 1 (true)
    cout << "Search APPLE: " << trie->search("APPLE") << endl;      // Output: 1 (true)
    cout << "Search APPL: " << trie->search("APPL") << endl;        // Output: 0 (false)
    cout << "StartsWith APP: " << trie->startsWith("APP") << endl;  // Output: 1 (true)
    cout << "StartsWith APE: " << trie->startsWith("APE") << endl;  // Output: 0 (false)
    trie->erase("APP");
    cout << "Search APP after erase: " << trie->search("APP") << endl;  // Output: 0 (false)
    cout << "Search APPLE after erase: " << trie->search("APPLE") << endl; // Output: 1 (true)
    return 0;
}