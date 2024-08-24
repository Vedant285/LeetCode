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
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, -1)));

        return solve(0, 0, m - 1,n, m, grid, dp);
    }
};