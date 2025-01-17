class Solution {
public:
    int coinChange(vector<int>& arr, int amount) {
        int n = arr.size();
        vector<vector<long long>>dp(n, vector<long long>(amount + 1));

        for (int t = 0; t <= amount; t++) {
            if(t % arr[0] == 0) dp[0][t] = t/arr[0];
            else dp[0][t] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                int take = 1e9;
                if(arr[i] <= t) take = 1 + dp[i][t - arr[i]];
                int nottake = dp[i - 1][t];
                dp[i][t] = min(take, nottake);
            }
        }

        return dp[n - 1][amount] >= 1e9? -1: dp[n - 1][amount];
    }
};