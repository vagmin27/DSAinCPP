#include <bits/stdc++.h>
using namespace std;
int findMinimumCost(string str) {
    int n = str.length();
    if (n % 2 != 0) return -1;  // If the length is odd, balancing is impossible
    stack<char> s;
    for (int i = 0; i < n; i++) {
        char ch = str[i];
        if (ch == '{') {
            s.push(ch);
        }
        else {  // ch == '}'
            if (!s.empty() && s.top() == '{') {
                s.pop();  // Found a matching pair
            }
            else {
                s.push(ch);  // No match, push the closing brace
            }
        }
    }
    // Count unbalanced braces
    int a = 0; // Count of unbalanced '}'
    int b = 0; // Count of unbalanced '{'
    while (!s.empty()) {
        if (s.top() == '{') {
            b++;
        }
        else {
            a++;
        }
        s.pop();
    }
    // Each pair of unbalanced '{' or '}' needs to be matched
    // The cost to balance is (a + 1) / 2 + (b + 1) / 2
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}
int main() {
    string str;
    cout << "Enter the string of braces: ";
    cin >> str;

    int result = findMinimumCost(str);
    if (result == -1) {
        cout << "The string cannot be balanced.\n";
    } else {
        cout << "Minimum cost to balance the string: " << result << "\n";
    }
    return 0;
}