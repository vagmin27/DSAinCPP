#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int idx=0;
        int n=chars.size();
        while(i<n){
            int j=i+1;
            while(j<n && chars[i]==chars[j]){
                j++;
            }
            chars[idx++]=chars[i];
            int c=j-i;
            if(c>1){
                string cnt= to_string(c);
                for(char ch: cnt){
                    chars[idx++]=ch;
                }
            }
            i=j;
        }
        return idx;
    }
};
int main(){
    Solution s;
    vector<char> chars={'a','a','b','b','c','c','c'};
    int n=s.compress(chars);
    cout<<n<<endl;
}