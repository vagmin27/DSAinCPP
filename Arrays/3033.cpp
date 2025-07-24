#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> mxCol(c, INT_MIN);
        for (int i = 0; i < c; i++) {
            int mx = INT_MIN;
            for (int j = 0; j < r; j++) {
                mx = max(mx, matrix[j][i]);
            }
            mxCol[i] = mx;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = mxCol[j];
                }
            }
        }
        return matrix;
    }
};
int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, -1, 3},
        {4, 5, -1},
        {-1, 2, 6}
    };
    vector<vector<int>> modified = s.modifiedMatrix(matrix);
    for (const auto& row : modified) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}