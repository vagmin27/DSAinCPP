#include<bits/stdc++.h>
using namespace std;
string preToPost(string pre_exp) {
    int n = pre_exp.length();
    stack<string> st;
    for (int i = n - 1; i >= 0; i--) {
        char ch = pre_exp[i];
        if (isalnum(ch)) {
            // If the character is an operand, push it onto the stack
            st.push(string(1, ch));
        }
        else{
            // Ensure there are at least two operands in the stack
            if (st.size() < 2) {
                throw invalid_argument("Invalid prefix expression");
            }
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            // Concatenate in postfix order
            string ans = t1 + t2 + ch;
            st.push(ans);
        }
    }
    // The final result should be the only element left in the stack
    if (st.size() != 1) {
        throw invalid_argument("Invalid prefix expression");
    }

    return st.top();
}
int main() {
    string pre_exp = "*+AB-CD"; // Example prefix expression
    try {
        string post_exp = preToPost(pre_exp);
        cout << "Postfix: " << post_exp << endl; // Output should be "AB+CD-*"
    }
    catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }
    return 0;
}