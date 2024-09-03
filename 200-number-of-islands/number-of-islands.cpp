class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        int n = size(grid);
        int m = size(grid[0]);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nr = dr[k] + i;
            int nc = dc[k] + j;
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1') dfs(grid, nr, nc);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = size(grid);
        int m = size(grid[0]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};