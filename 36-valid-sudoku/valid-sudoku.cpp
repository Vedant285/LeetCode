#define vi vector<int>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vi(9, 0)), col(9, vi(9, 0)), sub(9, vi(9, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;

                int idx = board[i][j] - '0' - 1;
                int sum = (i / 3) * 3 + (j / 3);
                if(row[i][idx] || col[j][idx] || sub[idx][sum]) return false;

                row[i][idx] = col[j][idx] = sub[idx][sum] = 1;
            }
        }

        return true;
    }
};