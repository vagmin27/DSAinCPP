#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            st.push(s[i]);
            if(st.size()>=3){
                char first=st.top();
                st.pop();
                char second=st.top();
                st.pop();
                char third=st.top();
                st.pop();
                if(first==second && second==third){
                    st.push(second);
                    st.push(first);
                }
                else{
                    st.push(third);
                    st.push(second);
                    st.push(first);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3) {
            return s;
        }
        int j = 2;
        for (int i = 2; i < s.size(); ++i)
            if (s[i] != s[j - 1] || s[i] != s[j - 2])
                s[j++] = s[i];
        s.resize(j);
        return s;
    }
};
int main(){
    Solution s;
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    cout<<"Fancy string : "<<s.makeFancyString(str)<<endl;
}