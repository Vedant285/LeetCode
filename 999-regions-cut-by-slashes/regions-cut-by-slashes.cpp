class Solution {
public:
    void dfs(vector<vector<int>>& m, int r, int c, vector<vector<int>>& vis) {
        vis[r][c] = 1;
        int n = m.size();
        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < n && nr >= 0 && nc < n && nc >= 0 && !vis[nr][nc] && m[nr][nc] == 0)
                dfs(m, nr, nc, vis); 
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> m(n*3 , vector<int>(n * 3, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == '/') {
                    m[i*3][j*3 + 2] = 1;
                    m[i*3 + 1][j*3 +1] = 1;
                    m[i*3 + 2][j*3] = 1;
                }
                else if (grid[i][j] == '\\') {
                    m[i*3][j*3] = 1;
                    m[i*3 + 1][j*3 +1] = 1;
                    m[i*3 + 2][j*3 + 2] = 1;
                }
            }
        }
        vector<vector<int>>vis(n*3, vector<int>(n*3, 0));
        int cnt  = 0;
        for (int i = 0; i < n*3; i++) {
            for (int j = 0; j < n*3; j++) {
                if(m[i][j] == 0 && !vis[i][j]) {
                    dfs(m, i, j, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};