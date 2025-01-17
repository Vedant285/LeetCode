class Solution {
public:
    int n, m;

    int calculateMinimumHP(vector<vector<int>>& arr) {
        n = size(arr);
        m = size(arr[0]);
        
        vector<vector<int>>dp(n, vector<int>(m, 1e9));
        
        dp[n - 1][m - 1] = max(1, 1 - arr[n - 1][m - 1]);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if(i == n - 1 && j == m - 1) continue;

                int up = (i + 1 < n)?dp[i + 1][j]:1e9;
                int left = (j + 1 < m)? dp[i][j + 1]:1e9;
                dp[i][j] = max(1, min(up, left) - arr[i][j]);

            }
        }

        return dp[0][0];
    }
};