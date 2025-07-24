#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCount(int start, const string& s, unordered_set<string>& res) {
        if (start == s.size())
            return 0; // Base case: if we've reached the end of the string
        int maxi = 0; // To keep track of the maximum unique substrings count
        for (int i = start + 1; i <= s.size(); ++i) {
            string sub = s.substr(start, i - start); // Get the current substring
            // Check if the substring is unique
            if (res.find(sub) == res.end()) {
                res.insert(sub); // Add it to the set
                maxi = max(maxi, 1 + maxCount(i, s, res)); // Recur for the rest of the string
                res.erase(sub); // Backtrack: remove the substring from the set
            }
        }
        return maxi; // Return the maximum count found
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> res; // Set to store unique substrings
        return maxCount(0, s, res); // Start the recursion
    }
};
int main() {
    Solution solution; // Create an instance of the Solution class
    string s = "ababccc"; // Example input string
    int result = solution.maxUniqueSplit(s); // Call the method to get the result
    cout << "Maximum unique substrings: " << result << endl; // Output the result
    return 0; // Indicate successful completion
}