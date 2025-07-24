#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                str.push(ch);
            } else {
                if (!str.empty()) {
                    char top = str.top();
                    if ((ch == ')' && top == '(') || 
                        (ch == ']' && top == '[') || 
                        (ch == '}' && top == '{')) {
                        str.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return str.empty();
    }
};

int main() {
    Solution sol;
    string testStr;
    cout<<"Enter a string of parentheses: ";
    cin>>testStr;
    if(sol.isValid(testStr)) {
        cout<<"The string is valid."<<endl;
    }
    else{
        cout<<"The string is not valid."<<endl;
    }
    return 0;
}