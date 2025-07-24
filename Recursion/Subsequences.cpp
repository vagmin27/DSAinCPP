#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    void solve(string str,string s,int i, vector<string>& ans){
        if(i>=str.length()){
            if(s.length()>0){
                ans.push_back(s);
            }
            return;
        }
        solve(str,s,i+1,ans);
        char e=str[i];
        s.push_back(e);
        solve(str,s,i+1,ans);
    }
    public:
    vector<string> subsequences(string str){
        vector<string> ans;
        string s="";
        int i=0;
        solve(str,s,i,ans);
        return ans;
    }
};
int main(){
    Solution s;
    string str;
    cout<<"Enter the String: ";
    cin>>str;
    vector<string>v=s.subsequences(str);
    cout<<"All possible subsequences are: "<<endl;
    for(const string& ss : v){
        cout<<ss<<" ";
    }
}