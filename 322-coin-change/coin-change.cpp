class Solution {
public:
    int solve(int i, int t, vector<int>& arr, vector<vector<int>>&dp) {
        if(i == 0) {
            if(t % arr[0] == 0) return t/arr[0];
            return 1e9;
        }
        if(dp[i][t] != -1) return dp[i][t];
        int take = 1e9;
        if(arr[i] <= t) take = 1 + solve(i, t - arr[i], arr, dp);
        int nottake = solve(i - 1, t, arr, dp);
        return dp[i][t] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, amount, coins, dp);
        return ans >= 1e9? -1: ans;
    }
};