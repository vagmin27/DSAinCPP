#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isCircularSentence(string s) {
        string str = "";
        vector<string> v;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                v.push_back(str);
                str = "";
            }
            else {
                str += s[i];
            }
        }
        v.push_back(str);
        int n = v.size();
        if(n == 1) {
            string temp = v[0];
            int sz = temp.size();
            return temp[0] == temp[sz - 1];
        }
        char lastCh, StartCh;
        for(int i = 0; i < n; i++) {
            string temp = v[i];
            int sz = temp.size();
            if(i == 0) {
                StartCh = temp[0];
                lastCh = temp[sz - 1];
                continue;
            }
            if(lastCh != temp[0]) return false;
            if(i == n - 1 && StartCh != temp[sz - 1]) return false;
            lastCh = temp[sz - 1];
        }
        return true;
    }
};
int main() {
    Solution sol;
    string testSentence = "hello apple egg orange hello";
    bool result = sol.isCircularSentence(testSentence);
    cout << (result ? "Circular" : "Not Circular") << endl;
    return 0;
}