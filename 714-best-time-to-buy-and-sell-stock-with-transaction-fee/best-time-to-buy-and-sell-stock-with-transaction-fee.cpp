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
        //vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        vector<int> pre(2, 0), curr(2, 0);
        for(int idx = n - 1; idx >= 0; idx--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                if(canBuy) {
                    curr[canBuy] = max(-prices[idx] + pre[0], pre[1]);
                }
                else
                    curr[canBuy] = max(prices[idx] - fee + pre[1], pre[0]);
            }
            pre = curr;
        }

        return pre[1];
    }
};