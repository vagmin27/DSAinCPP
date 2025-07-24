#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int c = 0;  // The maximum depth encountered
        int cnt = 0; // The current depth counter
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                cnt++;  // Increase depth for '('
            }
            if (s[i] == ')') {
                c = max(cnt, c);  // Track the max depth
                cnt--;  // Decrease depth for ')'
            }
        }
        return c;  // Return the maximum depth
    }
};

int main() {
    Solution solution;
    string input;
    // Input string
    cout << "Enter a string with parentheses: ";
    cin >> input;
    // Calculate and print the max depth of parentheses
    int depth = solution.maxDepth(input);
    cout << "The maximum depth of nested parentheses is: " << depth << endl;
    return 0;
}