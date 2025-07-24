#include <bits/stdc++.h>
using namespace std;
bool findRedundantBrackets(string &s){
    stack<char> st;
    for(char ch:s){
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){
            bool isRedundant = true;
            while(!st.empty() && st.top() != '('){
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/'){
                    isRedundant = false; // Found an operator, so it's not redundant
                }
                st.pop();
            }
            // Pop the opening bracket
            if(!st.empty()){
                st.pop();
            }
            // If no operator was found, it's redundant
            if(isRedundant) return true;
        }
    }
    return false;
}
int main(){
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;
    if(findRedundantBrackets(expression)){
        cout << "Redundant brackets found." << endl;
    }
    else{
        cout << "No redundant brackets." << endl;
    }
    return 0;
}