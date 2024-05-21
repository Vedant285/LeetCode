#define vs vector<string>
#define vss vector<vs>
#define vi vector<int>
class Solution {
public:
    int cnt = 0;
    void solve(int col,int n, vi& t, vi& upper, vi& down) {
        if (col == n) {
            cnt ++;
            return;
        }
        for (int i =0 ; i< n;i++) {
            if (t[i] == 0 && upper[i+col] == 0 && down[n-1+col -i] == 0) {
                t[i] = 1;
                upper[i+col] = 1;
                down[n-1+col -i] =1;
                solve(col+1,n,t,upper,down );
                t[i] = 0;
                upper[i+col] = 0;
                down[n-1+col -i] =0;
            }
        }
    }
    int totalNQueens(int n) {
        vi t(n,0), upper(2*n -1), down(2*n -1);
        solve(0, n, t, upper, down);
        return cnt;
    }
};