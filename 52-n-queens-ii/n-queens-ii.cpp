#define vs vector<string>
#define vss vector<vs>
#define vi vector<int>
class Solution {
public:
    int cnt = 0;
    void solve(int col, vs& ans,int n, vi& t, vi& upper, vi& down) {
        if (col == n) {
            cnt ++;
            return;
        }
        for (int i =0 ; i< n;i++) {
            if (t[i] == 0 && upper[i+col] == 0 && down[n-1+col -i] == 0) {
                t[i] = 1;
                upper[i+col] = 1;
                down[n-1+col -i] =1;
                ans [i][col] = 'Q';
                solve(col+1, ans,n,t,upper,down );
                t[i] = 0;
                upper[i+col] = 0;
                down[n-1+col -i] =0;
                ans [i][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        string s(n,'.');
        vss board(n);
        vs ans(n);
        for (int i =0 ; i< n ; i++) {
            ans [i] = s;
        }
        vi t(n,0), upper(2*n -1), down(2*n -1);
        solve(0, ans, n, t, upper, down);
        return cnt;
    }
};