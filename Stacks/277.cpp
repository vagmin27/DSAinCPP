#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    bool knows(vector<vector<int>> mat , int a, int b, int n){
        if(mat[a][b]==1) return true;
        else return false;
    }
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int> s;
        int n=mat.size();
        for(int i=0;i<n;i++){
            s.push(i);
        }
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(knows(mat,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int candidate=s.top();
        bool rowCheck=false;
        int zeroCount=0;
        for(int i=0;i<n;i++){
            if(mat[candidate][i]==0) zeroCount++;
        }
        if(zeroCount==n){
            rowCheck=true;
        }
        bool colCheck=false;
        int oneCount=0;
        for(int i=0;i<n;i++){
            if(mat[i][candidate]==1) oneCount++;
        }
        if(oneCount==n-1){
            colCheck=true;
        }
        if(rowCheck==true && colCheck==true){
            return candidate;
        }
        else{
            return -1;
        }
    }
};
// class Celebrity{
// public:
// // Function to check if person a knows person b
// bool knows(const vector<vector<int>>& M, int a, int b) {
//     return M[a][b] == 1;
// }
// // Function to find the celebrity
// int findCelebrity(const vector<vector<int>>& M) {
//     int n = M.size();
//     int candidate = 0;
//     // Step 1: Find the candidate
//     for (int i = 1; i < n; ++i) {
//         if (knows(M, candidate, i)) {
//             candidate = i; // candidate can't be `candidate` if it knows `i`
//         }
//     }
//     // Step 2: Verify the candidate
//     for (int i = 0; i < n; ++i) {
//         if (i != candidate) {
//             if (knows(M, candidate, i) || !knows(M, i, candidate)) {
//                 return -1; // No celebrity
//             }
//         }
//     }
//     return candidate; // Celebrity found
// }
// };
int main(){
    Solution s;
    // Celebrity c;
    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    // Initialize matrix with size n
    vector<vector<int>> mat(n, vector<int>(n));
    cout<<"Enter the elements of the matrix (0 or 1): "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int celebrity=s.celebrity(mat);
    // int celeb=c.findCelebrity(mat);
    if(celebrity==-1) {
        cout<<"No celebrity present in the matrix!!"<<endl;
    }
    else{
        cout<<"Celebrity index is: "<<celebrity<<endl;
    }
}