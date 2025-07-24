#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static const int SIZE = 9;
    static const char EMPTY = '.';
    bool check(vector<vector<char>>& board, int row, int col, char ch) {
        for (int j = 0; j < SIZE; j++) {
            if (board[row][j] == ch) return false;
        }
        for (int i = 0; i < SIZE; i++) {
            if (board[i][col] == ch) return false;
        }
        int rMin = row - (row % 3);
        int cMin = col - (col % 3);
        for (int i = rMin; i < rMin + 3; i++) {
            for (int j = cMin; j < cMin + 3; j++) {
                if (board[i][j] == ch) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == EMPTY) {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (check(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (solve(board)) return true;
                            board[i][j] = EMPTY;
                        }
                    }
                    return false; // No valid number found
                }
            }
        }
        return true; // Solved
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    void printBoard(const vector<vector<char>>& board) {
        for (const auto& row : board) {
            for (char cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    cout << "Original Sudoku Board:" << endl;
    solution.printBoard(board);
    solution.solveSudoku(board);
    cout << "\nSolved Sudoku Board:" << endl;
    solution.printBoard(board);
    return 0;
}
// #include <iostream>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     static const int SIZE = 9;
//     static const char EMPTY = '.';
//     bool check(vector<vector<char>>& board, int row, int col, char ch) {
//         for (int j = 0; j < SIZE; j++) {
//             if (board[row][j] == ch) return false;
//         }
//         for (int i = 0; i < SIZE; i++) {
//             if (board[i][col] == ch) return false;
//         }
//         int rMin = row - (row % 3);
//         int cMin = col - (col % 3);
//         for (int i = rMin; i < rMin + 3; i++) {
//             for (int j = cMin; j < cMin + 3; j++) {
//                 if (board[i][j] == ch) return false;
//             }
//         }
//         return true;
//     }
//     bool solve(vector<vector<char>>& board) {
//         for (int i = 0; i < SIZE; i++) {
//             for (int j = 0; j < SIZE; j++) {
//                 if (board[i][j] == EMPTY) {
//                     for (char ch = '1'; ch <= '9'; ch++) {
//                         if (check(board, i, j, ch)) {
//                             board[i][j] = ch;
//                             if (solve(board)) return true;
//                             board[i][j] = EMPTY;
//                         }
//                     }
//                     return false; // No valid number found
//                 }
//             }
//         }
//         return true; // Solved
//     }
//     void solveSudoku(vector<vector<char>>& board) {
//         solve(board);
//     }
// };
// void printBoard(const vector<vector<char>>& board) {
//     for (const auto& row : board) {
//         for (char cell : row) {
//             cout << cell << ' ';
//         }
//         cout << endl;
//     }
// }
// int main() {
//     vector<vector<char>> board = {
//         {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
//     };
//     Solution solution;
//     solution.solveSudoku(board);
//     cout << "Solved Sudoku:" << endl;
//     printBoard(board);
//     return 0;
// }