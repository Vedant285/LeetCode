class Solution {
public:
    int n, m;
    
    void dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
            int newr = i + dr[k];
            int newc = j + dc[k];
            if(newr >= 0 && newc >= 0 && newr < n && newc < m && grid[newr][newc] == 1) {
                dfs(newr, newc, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 1) {
                    dfs(i, j, grid);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};