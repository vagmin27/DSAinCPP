#include<bits/stdc++.h>
using namespace std;
string FirstNonRepeating(string &s) {
    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";
    for (char ch : s) {
        count[ch]++;
        q.push(ch);
        // Remove repeating characters from the front of the queue
        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }
        // If the queue is not empty, append the front of the queue to the answer
        if (!q.empty()) {
            ans.push_back(q.front());
        }
        else {
            ans.push_back('#'); // If all characters are repeating, append '#'
        }
    }
    return ans;
}
int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    string result = FirstNonRepeating(input);
    cout << "First non-repeating characters: " << result << endl;
    return 0;
}