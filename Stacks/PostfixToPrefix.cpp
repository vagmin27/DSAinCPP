#include<bits/stdc++.h>
using namespace std;
string postToPre(string post_exp) {
    if (post_exp.empty()) return "";
    stack<string> st;
    for (char ch : post_exp) {
        if (isalnum(ch)) {
            // If the character is an operand, push it to the stack
            st.push(string(1, ch));
        }
        else {
            // Operator encountered
            if (st.size() < 2) {
                cerr << "Error: Invalid postfix expression." << endl;
                return "";
            }
            string t1 = st.top(); st.pop(); // First operand
            string t2 = st.top(); st.pop(); // Second operand
            string ans = ch + t2 + t1; // Construct the prefix expression
            st.push(ans); // Push it back onto the stack
        }
    }
    if (st.size() != 1) {
        cerr << "Error: Invalid postfix expression." << endl;
        return "";
    }
    return st.top();
}
int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;
    string prefix = postToPre(postfix);
    if (!prefix.empty()) {
        cout << "Prefix expression: " << prefix << endl;
    }
    return 0;
}