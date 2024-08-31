class Solution {
public:
    int n;
    int solve(int idx, int canBuy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(idx == n || cap == 0) return 0;

        if(dp[idx][canBuy][cap] != -1) return dp[idx][canBuy][cap];

        if(canBuy) {
            return dp[idx][canBuy][cap] = max(-prices[idx] + solve(idx + 1, 0, cap, prices, dp), solve(idx + 1, 1, cap, prices, dp));
        }
        return dp[idx][canBuy][cap] = max(prices[idx] + solve(idx + 1, 1, cap - 1, prices, dp), solve(idx + 1, 0, cap, prices, dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, 1, k, prices, dp);
    }
};