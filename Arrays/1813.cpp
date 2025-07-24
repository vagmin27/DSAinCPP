#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void store(string& s, vector<string>& mp){
        string a = "";
        for(auto c: s){
            if(c == ' '){
                mp.push_back(a);
                a = "";
            }else{
                a += c;
            }
        }
        if(a.length() > 0)  mp.push_back(a);
    }
    bool check(vector<string>& m1, vector<string>& m2){
        int c = 0;
        for(int i=0; i<m2.size(); i++){
            if(m2[i] != m1[i]){
                break;
            }else c++;
        }
        int j = m1.size()-1;
        for(int i=m2.size()-1; i>=0; i--){
            if(m2[i] != m1[j]){
                break;
            }else{
                c++;
            }
            j--;
        }
        return c >= m2.size();
    }
    
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> m1, m2;
        store(sentence1,m1);
        store(sentence2, m2);
        int n = sentence1.length();
        int m = sentence2.length();
        if(n > m){
            if(check(m1,m2)) return true;
        }else{
            if(check(m2,m1)) return true;
        }
        return false;
    }
};
int main(){
    Solution s;
    string str1,str2;
    cout<<"Enter the first sentence: ";
    getline(cin,str1);
    cout<<endl;
    cout<<"Enter the second sentence: ";
    getline(cin,str2);
    cout<<s.areSentencesSimilar(str1,str2)<<endl;
}