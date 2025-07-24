// #include<bits/stdc++.h>
// using namespace std;
// //Love babber
// class Solution{
//     bool isSafe(int row,int col,vector<vector<int>>&board,int val){
//         int n=board[0].size();
//         for(int i=0;i<n;i++){
//             //row check
//             if(board[row][i]==val) return false;
//             //col check
//             if(board[i][col]==val) return false;
//             //3*3 matrix check
//             if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
//             //board[3*(row/3)+i/3][3*(col/3)+i%3]: This accesses each cell in the current 3x3 subgrid.
//             //i/3 gives the row index within the subgrid.
//             // i%3 gives the column index within the subgrid.
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool solve(vector<vector<int>>& board){
//         int n=board[0].size();
//         for(int row=0;row<n;row++){
//             for(int col=0;col<n;col++){
//                 //empty cell
//                 if(board[row][col]==0){
//                     for(int val=1;val<=9;val++){
//                         if(isSafe(row,col,board,val)){
//                             board[row][col]=val;
//                             //recursive call
//                             bool isTrue=solve(board);
//                             if(isTrue) return true;
//                             else{
//                                 //backtrack
//                                 board[row][col]=0;
//                             }
//                         }
//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
//     public:
//     void solveSudoku(vector<vector<int>>& suduko) {
//         solve(suduko);
//     }
// };
// // ***V.V.V IMP***
// class Solution {
// public:
//     bool check(vector<vector<char>> &board, int i, int j, char val) {
//         int row = i - i % 3;
//         int col = j - j % 3;
//         // Check the column
//         for (int x = 0; x < 9; x++) 
//             if (board[x][j] == val) return false;
//         // Check the row
//         for (int y = 0; y < 9; y++) 
//             if (board[i][y] == val) return false;
//         // Check the 3x3 sub-box
//         for (int x = 0; x < 3; x++) 
//             for (int y = 0; y < 3; y++)
//                 if (board[row + x][col + y] == val) return false;
//         return true;
//     }
//     bool solve(vector<vector<char>> &board, int i, int j) {
//         if (i == 9) return true; // If we've filled all rows, we're done
//         if (j == 9) return solve(board, i + 1, 0); // Move to the next row
//         if (board[i][j] != '.') return solve(board, i, j + 1); // Skip filled cells
//         for (char c = '1'; c <= '9'; c++) {
//             if (check(board, i, j, c)) {
//                 board[i][j] = c; // Place the number
//                 if (solve(board, i, j + 1)) return true; // Recur to the next cell
//                 board[i][j] = '.'; // Backtrack
//             }
//         }
//         return false; // Trigger backtracking
//     }
//     void solveSudoku(vector<vector<char>>& board) {
//         solve(board, 0, 0);
//     }
// };
// //T.C O(9^k); k->no of empty boxes.
// //S.C O(k)
// // int main() {
// //     vector<vector<int>> sudoku = {
// //         {5, 3, 0, 0, 7, 0, 0, 0, 0},
// //         {6, 0, 0, 1, 9, 5, 0, 0, 0},
// //         {0, 9, 8, 0, 0, 0, 0, 6, 0},
// //         {8, 0, 0, 0, 6, 0, 0, 0, 3},
// //         {4, 0, 0, 8, 0, 3, 0, 0, 1},
// //         {7, 0, 0, 0, 2, 0, 0, 0, 6},
// //         {0, 6, 0, 0, 0, 0, 2, 8, 0},
// //         {0, 0, 0, 4, 1, 9, 0, 0, 5},
// //         {0, 0, 0, 0, 8, 0, 0, 7, 9}
// //     };
// //     Solution sol;
// //     sol.solveSudoku(sudoku);
// //     // Print the solved Sudoku board
// //     for (const auto& row : sudoku) {
// //         for (int num : row) {
// //             cout << num << " ";
// //         }
// //         cout << endl;
// //     }
// //     return 0;
// // }
// int main() {
//     Solution solution;
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
//     solution.solveSudoku(board);
//     // Print the solved board
//     for (const auto &row : board) {
//         for (char c : row) {
//             cout << c << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }