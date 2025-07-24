#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        stack <char> st;
        int maxlen = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push(s[i]);
                if(maxlen < st.size()){
                    maxlen = st.size();
                }
            }
            else if(s[i]==')'){
                st.pop();
            }
        }
        return maxlen;
    }
};
int main() {
    Solution sol;
    string s = "(1+(2*3)+((8)/4))+1";
    cout << "Maximum depth: " << sol.maxDepth(s) << endl;
    s = "(1)+((2))+(((3)))";
    cout << "Maximum depth: " << sol.maxDepth(s) << endl;
    s = "1+(2*3)/(2-1)";
    cout << "Maximum depth: " << sol.maxDepth(s) << endl;
    return 0;
}