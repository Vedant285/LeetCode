class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int>rowcnt(n, 0), colcnt(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    rowcnt[i]++;
                    colcnt[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && (rowcnt[i] > 1 || colcnt[j] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};