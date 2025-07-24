#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string compressedString(const string& word) {
        ostringstream sb;
        int count = 0;
        int i = 0;
        while (i < word.length()) {
            char c = word[i];
            count = 0;
            // Count occurrences of the current character
            while (i < word.length() && word[i] == c) {
                ++count;
                ++i;
            }
            // Split if count exceeds 9
            while (count > 0) {
                int currentCount = min(count, 9); // take max 9
                sb << currentCount << c; // append to string
                count -= currentCount; // reduce the count
            }
        }

        return sb.str();
    }
};
int main() {
    Solution solution;
    string result = solution.compressedString("aaabbbcccc");
    cout << "Compressed string: " << result << endl;
    return 0;
}