#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        int i = 0;
        int sign = 1;
        // Skip leading whitespace
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        // Check for sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        // Convert the digits
        while (i < s.size() && isdigit(s[i])) {
            // Check for overflow
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num * 10 + (s[i] - '0');
            i++;
        }

        return num * sign;
    }
};
int main() {
    Solution s;
    string str;
    cout << "Enter a string to convert to integer: ";
    getline(cin, str);
    int ans = s.myAtoi(str);
    cout << "Converted integer: " << ans << endl;
    return 0;
}