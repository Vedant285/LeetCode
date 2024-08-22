class Solution {
public:
    int solve(int i,int t, vector<int>& arr ) {
        if (i == 0) {
            return (t % arr[0] == 0);
        }
        int nottake = solve(i - 1, t, arr);
        int take = 0;
        if (arr[i] <= t) take = solve(i, t - arr[i], arr);
        return take + nottake;
    }
    int change(int amount, vector<int>& arr) {
        int n = arr.size();
        vector<vector<long>> dp(n, vector<long>(amount + 1, 0));

        for (int i = 0; i <= amount; i++) {
            if (i % arr[0] == 0) dp[0][i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                int nottake = dp[i - 1][t];
                int take = 0;
                if (arr[i] <= t) take = dp[i][t - arr[i]];
                dp[i][t] = take + nottake;
            }
        }
        return dp[n - 1][amount];
    }
};