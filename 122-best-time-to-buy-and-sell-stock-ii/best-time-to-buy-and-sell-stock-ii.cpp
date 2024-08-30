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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 0, prices, n, dp);
    }
};