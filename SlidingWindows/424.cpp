#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxF = 0;
        int maxLen = 0;
        vector<int> hash(26, 0);

        for (int r = 0; r < s.size(); ++r) {
            hash[s[r] - 'A']++;
            maxF = max(maxF, hash[s[r] - 'A']);

            // If more than k characters need to be replaced
            if ((r - l + 1) - maxF > k) {
                hash[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution solution;

    // Example test case
    string s = "AABABBA";
    int k = 1;
    int result = solution.characterReplacement(s, k);

    cout << "Longest substring after " << k << " replacements: " << result << endl;

    return 0;
}
