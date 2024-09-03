class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int &cnt) {
        grid[i][j] = 0;
        int n = size(grid);
        int m = size(grid[0]);
        cnt++;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nr = dr[k] + i;
            int nc = dc[k] + j;
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) dfs(grid, nr, nc, cnt);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = size(grid);
        int m = size(grid[0]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int cnt = 0;
                    dfs(grid, i, j, cnt);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;

    }
};