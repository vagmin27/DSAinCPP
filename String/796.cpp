#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        int i=0;
        if(m!=n) {
            return false;
        } 
        while(i<n) {
            if(s == goal) {
                return true;
            }
            char a=s[0];
            for(int j=0;j<n-1;j++) {
                s[j]=s[j+1];
            }
            s[n-1]=a;
            i++;
        }
        return false;
    }
};
int main() {
    Solution sol;
    string s1="abcde";
    string goal1="cdeab";
    cout<<boolalpha; // Print boolean values as true/false
    cout<<"Can \""<<s1<<"\" be rotated to \""<<goal1 <<"\"? "<<sol.rotateString(s1, goal1)<<endl;
    string s2="abcde";
    string goal2="abced";
    cout<<"Can \""<<s2<<"\" be rotated to \""<<goal2<<"\"? "<<sol.rotateString(s2, goal2)<<endl;
}