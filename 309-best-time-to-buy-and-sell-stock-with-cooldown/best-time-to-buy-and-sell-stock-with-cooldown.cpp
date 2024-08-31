class Solution {
public:
    int n;
    int solve(int idx, int canBuy, vector<int>& prices, vector<vector<int>>& dp){
        if(idx >= n) return 0;

        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];

        if(canBuy) {
            return dp[idx][canBuy] = max(-prices[idx] + solve(idx + 1, 0, prices, dp), solve(idx + 1, 1, prices, dp));
        }
        return dp[idx][canBuy] = max(prices[idx] + solve(idx + 2, 1, prices, dp), solve(idx + 1, 0, prices, dp));
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};