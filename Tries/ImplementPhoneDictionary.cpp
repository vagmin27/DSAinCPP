#include <bits/stdc++.h>
using namespace std;

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
        int charIndex = word[index] - 'A';
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

    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            TrieNode* next = curr->children[ch - 'A'];
            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";
        for (int i = 0; i < str.length(); i++) {
            char lastch = str[i];
            prefix.push_back(lastch);
            TrieNode* curr = prev->children[lastch - 'A'];
            if (curr == NULL) {
                break;
            }
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {
    Trie* t = new Trie();
    for (int i = 0; i < contactList.size(); i++) {
        string str = contactList[i];
        t->insert(str);
    }
    return t->getSuggestions(queryStr);
}

int main() {
    vector<string> contactList = {"APPLE", "APRICOT", "BANANA", "APE"};
    string queryStr = "APP";
    vector<vector<string>> result = phoneDirectory(contactList, queryStr);

    for (auto suggestions : result) {
        for (auto word : suggestions) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}