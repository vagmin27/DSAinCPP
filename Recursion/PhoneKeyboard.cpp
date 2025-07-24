// #include<iostream>
// #include<vector>
// #include<string>
// using namespace std;
// class Solution{
//     void solve(string digits,string s, int i,vector<string>&ans,string mp[]){
//         if(i>=digits.length()){
//             ans.push_back(s);
//             return;
//         }
//         int n=digits[i]-'0';
//         string value=mp[n];
//         for(char i:value){
//             // s.push_back(value[i]);
//             solve(digits,s,i+1,ans,mp);
//         }
//     }
//     public:
//     vector<string>letterCombinations(string digits){
//         vector<string>ans;
//         string s;
//         if(digits.empty()) return ans;
//         int i=0;
//         string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//         solve(digits,"",0,ans,mp);
//         return ans;
//     }
// };
// int main(){
//     Solution s;
//     string digits;
//     cout<<"Enter the digits : ";
//     cin>>digits;
//     vector<string>v=s.letterCombinations(digits);
//     cout<<"All possible combinations are: "<<endl;
//     for(const string& i:v){
//         cout<<i<<" ";
//     }
// }
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void solve(string digits, string current, int index, vector<string>& result, string mapping[]) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        int digit = digits[index] - '0';
        string letters = mapping[digit];
        for (char letter : letters) {
            solve(digits, current + letter, index + 1, result, mapping);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, "", 0, result, mapping);
        return result;
    }
};

int main() {
    Solution solution;
    string digits;
    cout << "Enter the digits: ";
    cin >> digits;
    vector<string> combinations = solution.letterCombinations(digits);
    cout << "All possible combinations are: " << endl;
    for (const string& combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;
}