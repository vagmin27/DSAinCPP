#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int seen[3] = {-1, -1, -1};
        int cnt = 0;
        for (int r = 0; r < s.length(); ++r) {
            seen[s[r] - 'a'] = r;
            int idx = min(seen[0], min(seen[1], seen[2]));
            cnt += (idx + 1); // only add when all characters seen
        }
        return cnt;
    }
};

int main() {
    Solution solution;

    string s = "abcabc";
    int result = solution.numberOfSubstrings(s);

    cout << "Number of substrings containing all three characters: " << result << endl;

    return 0;
}
