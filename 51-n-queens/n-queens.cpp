class Solution {
public:
    bool isValid(int row, int col, vector<string>&board, int n) {
        int nr= row;
        int nc = col;
        while (nr >=0 && nc >=0) {
            if (board[nr][nc] == 'Q') return false;
            nr --;
            nc --;
        }
        nr = row;
        nc = col;
        while (nc >= 0) {
            if (board[nr][nc] == 'Q')return false;
            nc--;
        }
        nr = row;
        nc = col;
        while (nr < n && nc >= 0) {
            if (board[nr][nc] == 'Q')return false;
            nr ++;
            nc --;
        }
        return true;
    }
    void solve(int col, vector<vector<string>>& ans, vector<string>&t, int n) {
        if (col == n) {
            ans.push_back(t);
            return;
        }
        for (int i = 0 ; i < n ; i++) {
            if (isValid(i,col, t, n)) {
                t[i][col] = 'Q';
                solve(col+1, ans, t, n);
                t[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n,'.');
        vector<string>t(n);
        for (int i =0 ;i < n ; i ++) {
            t[i] = s;
        }
        solve(0, ans, t, n);
        return ans;
    }
};