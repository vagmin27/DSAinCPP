#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0);
        int m = t.size();
        int n = s.size();
        if (n < m) return "";

        for (char c : t) {
            hash[c]++;
        }

        int l = 0, r = 0, minLen = INT_MAX, start = 0, cnt = m;

        while (r < n) {
            if (hash[s[r]] > 0) {
                cnt--;
            }
            hash[s[r]]--;
            r++;

            while (cnt == 0) {
                if (r - l < minLen) {
                    minLen = r - l;
                    start = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt++;
                }
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = sol.minWindow(s, t);
    cout << "Minimum window substring: " << result << endl;

    return 0;
}
