class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) dp[n - 1][i] = arr[n - 1][i];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {

                int a = arr[i][j] + dp[i + 1][j];
                int c = arr[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(a, c);
            }
        }
        return dp[0][0];
    }
};