#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool searchNext(vector<vector<char>>&board,string word,int row,int col,int idx,int m,int n) {
        // if index reaches at the end that means we have found the word
        if (idx==word.length())
            return true;
        // Checking the boundaries if the character at which we are placed is not the required character
        if (row<0 || col<0 || row==m || col==n || board[row][col]!=word[idx] or board[row][col] == '!')
            return false;
        // this is to prevent reusing of the same character
        char c=board[row][col];
        board[row][col]='!';
        // top direction
        bool top=searchNext(board,word,row-1,col,idx+1,m,n);
        // right direction
        bool right = searchNext(board,word,row,col+1,idx+1,m,n);
        // bottom direction
        bool bottom = searchNext(board,word,row+1,col,idx+1,m,n);
        // left direction
        bool left = searchNext(board,word,row,col-1,idx+1,m,n);
        board[row][col] = c; // undo change
        return top || right || bottom || left;
    }
    bool exist(vector<vector<char>>board,string word) {
        int m=board.size();
        int n=board[0].size();
        int idx=0;
        // First search the first character
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (board[i][j]==word[idx]) {
                    if (searchNext(board,word,i,j,idx,m,n))
                        return true;
                }
            }
        }
        return false;
    }
};
int main() {
    Solution s;
    vector<vector<char>> board {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
        };
    string word = "ABCCED";
    bool res = s.exist(board,word);
    if(res==1)
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}