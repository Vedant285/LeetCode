class Solution {
    
    void dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == '1') {
                dfs(nr, nc, grid);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    dfs(i, j, grid);
                    cnt++;
                } 
            }
        }   
        return cnt;
    }
};