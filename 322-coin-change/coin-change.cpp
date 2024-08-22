class Solution {
public:
    int solve(int i, vector<int>& arr, int t, vector<vector<int>>& dp) {

        if(i == 0) {
            if(t % arr[0] == 0) return t / arr[0];
            return 1e9;
        }
        if(dp[i][t] != -1) return dp[i][t];
        int nottake = solve(i - 1, arr, t, dp);
        int take = INT_MAX;
        if(arr[i] <= t) take = 1 + solve(i, arr, t - arr[i], dp);

        return dp[i][t] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, coins, amount, dp);
        if (ans >= 1e9) return -1;
        return ans;
    }
};