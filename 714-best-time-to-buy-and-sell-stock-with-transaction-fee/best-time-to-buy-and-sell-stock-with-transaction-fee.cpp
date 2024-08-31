class Solution {
public:
     int n;
    int solve(int idx, int canBuy, vector<int>& prices, int fee, vector<vector<int>>& dp){
        if(idx == n) return 0;

        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];

        if(canBuy) {
            return dp[idx][canBuy] = max(-prices[idx] + solve(idx + 1, 0, prices, fee, dp), solve(idx + 1, 1, prices, fee, dp));
        }
        return dp[idx][canBuy] = max(prices[idx] - fee + solve(idx + 1, 1, prices, fee, dp), solve(idx + 1, 0, prices, fee, dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, -1));
        return solve(0, 1, prices, fee, dp);
    }
};