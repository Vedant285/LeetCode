class Solution {
public:
    int solve(int i, int c, vector<int>& arr, int n, vector<vector<int>>& dp) {

        if(i == n) return 0;
        if(dp[i][c] != -1) return dp[i][c];
        int pr = 0;
        if(c == 0) {
            pr = max(-arr[i] + solve(i + 1, 1, arr, n, dp), solve(i + 1, 0, arr, n, dp));
        }
        else {
            pr = max(arr[i] + solve(i + 1, 0, arr, n, dp), solve(i + 1, 1, arr, n, dp));
        }
        return dp[i][c] = pr;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int c = 0; c <= 1; c++) {
                int pr = 0;
                if(c == 0) {
                    pr = max(-arr[i] + dp[i + 1][1], dp[i + 1][0]);
                }
                else {
                    pr = max(arr[i] + dp[i + 1][0], dp[i + 1][1]);
                }
                dp[i][c] = pr;
            }
        }
        return dp[0][0];
    }
};