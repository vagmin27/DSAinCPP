#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int open, int close, int n, vector<string> &ans, string &str) {
        if (open == n && close == n) {
            ans.push_back(str);
            return;
        }
        if (open < n) {
            str.push_back('(');
            solve(open + 1, close, n, ans, str); 
            str.pop_back();
        }
        if (close < open) {
            str.push_back(')');
            solve(open, close + 1, n, ans, str); 
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        solve(0, 0, n, ans, str);
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 3;
    vector<string> result = sol.generateParenthesis(n);
    for (const string &s : result) {
        cout << s << endl;
    }
    return 0;
}