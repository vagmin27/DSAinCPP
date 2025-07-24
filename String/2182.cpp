#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0);
        // Count the frequency of each character in the string
        for (auto ch : s) {
            count[ch - 'a']++;
        }
        string result = "";
        int i = 25;  // Start from 'z' (index 25)
        while (i >= 0) {
            if (count[i] == 0) {
                i--;  // Move to the next smaller character
                continue;
            }
            // Add the characters with respect to the repeat limit
            int freq = min(repeatLimit, count[i]);
            result.append(freq, 'a' + i);  // Append the character 'i' (corresponding to 'a' + i)
            count[i] -= freq;  // Decrease the count for the character
            // If there are still characters left of this type, attempt to place one smaller character
            if (count[i] > 0) {
                int j = i - 1;
                // Find the next available character (greater than 0 in count)
                while (j >= 0 && count[j] <= 0) {
                    j--;
                }
                // If a valid character is found, add it to the result
                if (j >= 0) {
                    result.push_back('a' + j);
                    count[j]--;
                }
            }
        }
        return result;
    }
};
int main() {
    Solution solution;
    string s = "cczazcc";
    int repeatLimit = 2;
    cout << solution.repeatLimitedString(s, repeatLimit) << endl;  // Expected output: "zzccaz"
    return 0;
}