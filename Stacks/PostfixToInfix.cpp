#include <bits/stdc++.h>
using namespace std;
string postToInfix(string exp) {
    if (exp.empty()) return ""; // Handle empty expression
    stack<string> st;
    int n = exp.length();
    for (int i = 0; i < n; ++i) {
        char c = exp[i];
        if (isalnum(c)) { // Check if the character is alphanumeric
            st.push(string(1, c)); // Push the character as a string
        }
        else {
            // Pop the top two elements from the stack
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            // Directly create the new string
            st.push('(' + t2 + c + t1 + ')');
        }
    }
    return st.top(); // The result will be on top of the stack
}
int main() {
    string postfixExp;
    cout << "Enter a postfix expression: ";
    cin >> postfixExp;
    string infixExp = postToInfix(postfixExp);
    cout << "Infix expression: " << infixExp << endl;
    return 0;
}