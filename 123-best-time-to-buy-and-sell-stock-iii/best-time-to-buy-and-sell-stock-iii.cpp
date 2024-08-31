class Solution {
public:
    int n;
    int solve(int idx, int canBuy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(idx == n || cap == 0) return 0;
        if(dp[idx][canBuy][cap] != -1) return dp[idx][canBuy][cap];
        if(canBuy) {
            return dp[idx][canBuy][cap] = max(-prices[idx] + solve(idx + 1, 0, cap,prices, dp), solve(idx + 1, 1, cap, prices, dp));
        }
        return  dp[idx][canBuy][cap] = max(prices[idx] + solve(idx + 1, 1, cap - 1, prices, dp), solve(idx + 1, 0, cap, prices,dp));

    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int idx = n - 1; idx >= 0; idx--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if(canBuy) {
                        dp[idx][canBuy][cap] = max(-prices[idx] + dp[idx + 1][0][cap], dp[idx + 1][1][cap]);
                    }
                    else
                        dp[idx][canBuy][cap] = max(prices[idx] + dp[idx + 1][1][cap - 1], dp[idx + 1][0][cap]);
                }
            }
        }

        return dp[0][1][2];
    }
};