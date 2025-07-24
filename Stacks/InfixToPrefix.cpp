#include <bits/stdc++.h>
using namespace std;
int priority(char ch) {
    if (ch == '^') return 3;  // Highest precedence
    if (ch == '*' || ch == '/') return 2;  // Medium precedence
    if (ch == '+' || ch == '-') return 1;  // Lowest precedence
    return -1;  // For non-operators
}
string infixToPrefix(string s) {
    reverse(s.begin(), s.end());  // Reverse the infix expression
    stack<char> st;
    string ans = "";
    int n = s.length();
    for (int i = 0; i < n; i++) {
        char current = s[i];
        // If the character is an operand, add it to the result
        // if((s[i]>='a'&& s[i]<='z') || (s[i]>='A'&& s[i]<='Z') || (s[i]>='0'&& s[i]<='9')){
        if (isalnum(current)) {
            ans += current;
        }
        // If the character is ')', push it to the stack
        else if (current == ')') {
            st.push(current);
        }
        // If the character is '(', pop from stack until ')' is found
        else if (current == '(') {
            while (!st.empty() && st.top() != ')') {
                ans += st.top();
                st.pop();
            }
            st.pop();  // Remove the ')' from the stack
        }
        // An operator is encountered
        else {
            if (current == '^') {
                while (!st.empty() && priority(current) < priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            } else {
                while (!st.empty() && priority(current) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(current);
        }
    }
    // Pop all remaining operators from the stack
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    
    reverse(ans.begin(), ans.end());  // Reverse the result to get prefix
    return ans;
}
int main() {
    string infix = "(A-B/C)*(A/K-L)";
    string prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;  // Expected output: *-A/B-C/-AKL
    return 0;
}