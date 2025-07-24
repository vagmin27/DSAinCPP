#include <bits/stdc++.h>
using namespace std;

string preToInfix(const string &pre_exp) {
    if (pre_exp.empty()) return "";
    stack<string> st;
    for (int i = pre_exp.length() - 1; i >= 0; --i) {
        char c = pre_exp[i];
        // Skip spaces
        if (isspace(c)) continue;
        if (isalnum(c)) {
            st.push(string(1, c)); // Push the operand as a string
        }
        else {
            // Ensure there are at least two operands on the stack
            if (st.size() < 2) {
                throw invalid_argument("Invalid prefix expression");
            }
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string ans = '(' + t1 + c + t2 + ')'; // Form the infix expression
            st.push(ans);
        }
    }
    if (st.size() != 1) {
        throw invalid_argument("Invalid prefix expression");
    }
    return st.top();
}

int main() {
    string prefix_expr;
    cout << "Enter a prefix expression: ";
    getline(cin, prefix_expr);

    try {
        string infix_expr = preToInfix(prefix_expr);
        cout << "Infix expression: " << infix_expr << endl;
    } catch (const invalid_argument &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
