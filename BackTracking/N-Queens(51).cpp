#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n) {
        int x = row;
        int y = col;
        // Check for same row
        while (y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            }
            y--;
        }
        x = row;
        y = col;
        // Check for upper diagonal
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            }
            x--;
            y--;
        }
        x = row;
        y = col;
        // Check for lower diagonal
        while (x < n && y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n) {
        // Base case
        if (col == n) {
            ans.push_back(board);
            return;
        }
        // Solve 1 case and rest recursion will handle
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                // Put queen on board
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                // Backtrack
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, ans, board, n);
        return ans;
    }
};
int main() {
    Solution solution;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<vector<string>> result = solution.solveNQueens(n);
    cout << "Solutions for " << n << " Queens:" << endl;
    for (const auto& board : result) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}