#include <bits/stdc++.h>
using namespace std;
int priority(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return -1; // For non-operators
}
string infixToPostfix(string s) {
    int i = 0;
    stack<char> st;
    string ans = "";
    int n = s.length();
    while(i < n) {
        char current = s[i];
        // If the character is an operand, add it to output
        if(isalnum(current)) {
        // if((s[i]>='a'&& s[i]<='z') || (s[i]>='A'&& s[i]<='Z') || (s[i]>='0'&& s[i]<='9')){
            ans += current;
        }
        // If the character is '(', push it to stack
        else if(current == '(') {
            st.push(current);
        }
        // If the character is ')', pop and output from the stack until an '(' is encountered
        else if(current == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); // Pop the '(' from the stack
        }
        // An operator is encountered
        else{
            while (!st.empty() && priority(current) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(current);
        }
        i++;
    }
    // Pop all the operators from the stack
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}
int main() {
    string infix = "A+B*(C^D-E)";
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;  // Output should be "ABCD^E-*+"
    return 0;
}