class Solution {
public:
    int n;
    int solve(int i, int bos, vector<int>& arr, vector<vector<int>>& dp) {
        if(i == n) return 0;
        if(dp[i][bos] != -1) return dp[i][bos];

        if(bos == 0) {
            return  dp[i][bos] = max(-arr[i] + solve(i + 1, 1, arr, dp), solve(i + 1, 0, arr, dp));
        }
        return dp[i][bos] = max(arr[i] + solve(i + 1, 0, arr, dp), solve(i + 1, 1, arr, dp));
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return solve(0, 0, prices, dp);
    }
};