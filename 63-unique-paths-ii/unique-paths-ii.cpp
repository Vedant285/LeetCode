class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) return 0;
        vector<vector<int>>dp(n, vector<int>(m, 0));
        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(i == 0 && j == 0) continue;
                    
                int up = (i - 1 >= 0 && obstacleGrid[i - 1][j] != 1) ? dp[i - 1][j]:0;
                int left = (j - 1 >= 0 && obstacleGrid[i][j -1] != 1) ? dp[i][j - 1]:0;
                dp[i][j]=  up + left;
            }
        }

        return dp[n - 1][m - 1];
    }
};