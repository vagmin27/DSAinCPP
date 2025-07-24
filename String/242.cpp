#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) return false;
        }
        return true;
    }
};
int main() {
    Solution sol;
    string s1 = "anagram";
    string t1 = "nagaram";
    cout << "Is '" << s1 << "' an anagram of '" << t1 << "'? " << (sol.isAnagram(s1, t1) ? "Yes" : "No") << endl;
    string s2 = "rat";
    string t2 = "car";
    cout << "Is '" << s2 << "' an anagram of '" << t2 << "'? "<< (sol.isAnagram(s2, t2) ? "Yes" : "No") << endl;
    return 0;
}