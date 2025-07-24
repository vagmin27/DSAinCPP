#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string s, int k) {
        // If k is equal to the length of s, remove all digits, return "0"
        if(k == s.length()) return "0";
        stack<char> st;
        // Iterate over the digits in the string
        for(int i = 0; i < s.length(); i++) {
            // Remove digits from the stack if they are larger than the current one
            while (!st.empty() && k > 0 && (st.top() - '0') > (s[i] - '0')) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        // If there are still digits to remove, pop from the stack
        while (k > 0) {
            st.pop();
            k--;
        }
        // Build the result from the stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        // Remove leading zeros
        while (ans.size() != 0 && ans.back() == '0') {
            ans.pop_back();
        }
        // Reverse the string to correct the order
        reverse(ans.begin(), ans.end());
        // If the result is empty, return "0"
        if (ans.empty()) return "0";
        return ans;
    }
};
int main() {
    Solution sol;
    string s = "1432219";
    int k = 3;
    cout << "Result: " << sol.removeKdigits(s, k) << endl; // Output: "1219"
    return 0;
}