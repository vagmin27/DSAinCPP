#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        // Traverse each digit in the number string
        for (int i = 0; i < num.size(); i++) {
            // Pop the stack while the current digit is smaller than the top of the stack
            // and we still have digits left to remove
            while (!st.empty() && num[i] < st.top() && k > 0) {
                st.pop();
                k--;
            }
            // Add the current digit to the stack (skip leading zeroes)
            if (!st.empty() || num[i] != '0') {
                st.push(num[i]);
            }
        }
        // If k > 0, remove remaining digits from the stack
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        // If the stack is empty, return "0"
        if (st.empty()) return "0";
        // Build the result string from the stack
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        // Reverse the string because we built it from the top of the stack
        reverse(result.begin(), result.end());
        return result;
    }
};
int main() {
    Solution sol;
    string num = "1432219";
    int k = 3;
    cout << "Result: " << sol.removeKdigits(num, k) << endl;  // Output should be "1219"
    return 0;
}