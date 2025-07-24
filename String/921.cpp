#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.empty()) return 0;
        int lcount = 0, rcount = 0;
        for(char ch:s){
            if(ch == '('){
                lcount++;
            }
            else{
                if(lcount == 0){
                    rcount++;
                }
                else{
                    lcount--;
                }
            }
        }
        return lcount+rcount;
    }
};
int main(){
    Solution s;
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    cout<<"Minimum adds to make parentheses valid: "<<s.minAddToMakeValid(str)<<endl;
}