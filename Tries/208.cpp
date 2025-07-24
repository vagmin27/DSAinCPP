#include <iostream>
#include <string>
using namespace std;

// class Trie {
// private:
//     struct TrieNode {
//         struct TrieNode* child[26];
//         bool isEnd;
//     };
//     TrieNode* node;
// public:
//     Trie() { node = new TrieNode(); }
//     void insert(string word) {
//         TrieNode* cur = node;
//         for (char c : word) {
//             if (cur->child[c - 'a'] == NULL)
//                 cur->child[c - 'a'] = new TrieNode();
//             cur = cur->child[c - 'a'];
//         }
//         cur->isEnd = true;
//     }
//     bool search(string word) {
//         TrieNode* cur = node;
//         for (char c : word) {
//             if (cur->child[c - 'a'] == NULL)
//                 return false;
//             cur = cur->child[c - 'a'];
//         }
//         if (cur->isEnd == true)
//             return true;
//         return false;
//     }
//     bool startsWith(string prefix) {
//         TrieNode* cur = node;
//         for (char c : prefix) {
//             if (cur->child[c - 'a'] == NULL)
//                 return false;
//             cur = cur->child[c - 'a'];
//         }
//         return true;
//     }
// };

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
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
        int charIndex = word[index] - 'A'; // Assuming input is uppercase
        TrieNode* child;
        if (root->children[charIndex] != NULL) {
            child = root->children[charIndex];
        } else {
            child = new TrieNode(word[index]);
            root->children[charIndex] = child;
        }
        insertUtil(child, word, index + 1);
    }
    void insert(const string& word) {
        insertUtil(root, word, 0);
    }
    bool searchUtil(TrieNode* root, const string& word, int index) {
        if (index == word.length()) {
            return root->isTerminal;
        }
        int charIndex = word[index] - 'A';
        TrieNode* child = root->children[charIndex];
        if (child == NULL) {
            return false;
        }
        return searchUtil(child, word, index + 1);
    }
    bool search(const string& word) {
        return searchUtil(root, word, 0);
    }
    bool startsWithUtil(TrieNode* root, const string& prefix, int index) {
        if (index == prefix.length()) {
            return true;
        }
        int charIndex = prefix[index] - 'A';
        TrieNode* child = root->children[charIndex];
        if (child == NULL) {
            return false;
        }
        return startsWithUtil(child, prefix, index + 1);
    }
    bool startsWith(const string& prefix) {
        return startsWithUtil(root, prefix, 0);
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
    return 0;
}