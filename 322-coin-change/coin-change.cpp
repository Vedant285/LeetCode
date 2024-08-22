class Solution {
public:
    int coinChange(vector<int>& arr, int amo) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(amo + 1));
        
        for (int i = 0; i <= amo; i++) {
            if(i % arr[0] == 0) dp[0][i] = i / arr[0];
            else dp[0][i] = 1e9;
        }
        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amo; t++) {

                int nottake = dp[i - 1][t];
                int take = 1e9;
                if(arr[i] <= t) take = 1 + dp[i][t - arr[i]];

                dp[i][t] = min(take, nottake);
            }
        }

        if (dp[n - 1][amo] >= 1e9) return -1;
        return dp[n - 1][amo];
    }
};