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
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for(int canBuy = 0; canBuy <= 1; canBuy++) {
                if(canBuy == 1) {
                    dp[idx][canBuy] = max(-prices[idx] + dp[idx + 1][0], dp[idx + 1][1]);
                }
                else{
                    dp[idx][canBuy] = max(prices[idx] + dp[idx + 2][1], dp[idx + 1][0]);
                }
            }
        }

        return dp[0][1];
    }
};