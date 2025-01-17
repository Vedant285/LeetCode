class Solution {
public:
    int n, m;
    int solve(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if(i >= n || j >= m) return 1e9;
        
        if(i == n - 1 && j == m - 1) {
            return max(1, 1 - arr[n - 1][m - 1]);
        }
        if(dp[i][j] != -1) return dp[i][j];
        int up = solve(i + 1, j, arr, dp);
        int left = solve(i, j + 1, arr, dp);
        return dp[i][j] = max(1, min(up, left) - arr[i][j]);

    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = size(dungeon);
        m = size(dungeon[0]);
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(0, 0, dungeon, dp);
    }
};