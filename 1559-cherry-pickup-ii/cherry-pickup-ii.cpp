class Solution {
public:
    int solve(int r, int c1, int c2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if(r >= n || c1 >= m || c2 >= m || c1 < 0 || c2 < 0) return -1e9;

        if(r == n - 1) {
            if (c1 == c2) return grid[r][c1];
            return grid[r][c1] + grid[r][c2];
        }
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        int maxi = INT_MIN;
        for (int i = -1; i < 2; i++) {
            for(int j = -1; j < 2; j++) {
                int ans;
                if(c1 == c2)
                    ans = grid[r][c1] + solve(r + 1, c1 + i, c2 + j, n, m, grid, dp);
                else
                    ans = grid[r][c1] + grid[r][c2] + solve(r + 1, c1 + i, c2 + j, n, m, grid, dp);

                maxi = max(maxi, ans); 
            }
        }
        return dp[r][c1][c2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = size(grid[0]);
        int dp[n][m][m];
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) dp[n - 1][j1][j2] = grid[n - 1][j1];
                else dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
        for (int r = n - 2; r >= 0; r--) {
            for (int c1 = 0; c1 < m; c1++) {
                for (int c2 = 0; c2 < m; c2++) {
                    int maxi = 0;

                    for (int i = -1; i < 2; i++) {
                        for(int j = -1; j < 2; j++) {
                            int ans = 0;
                            if(c1 == c2){
                                if(r + 1 < n && c1 + i < m && c2 + j < m && c1 + i >= 0 && c2 + j >= 0)
                                    ans = grid[r][c1] + dp[r + 1][c1 + i][c2 + j];
                            }
                            else{
                                if(r + 1 < n && c1 + i < m && c2 + j < m && c1 + i >= 0 && c2 + j >= 0)
                                    ans = grid[r][c1] + grid[r][c2] + dp[r + 1][c1 + i][c2 + j];
                                else 
                                    ans += -1e8;
                            }

                            maxi = max(maxi, ans); 
                        }
                    }
                    dp[r][c1][c2] = maxi;
                }
            }
        }
        return dp[0][0][m - 1];
    }
};