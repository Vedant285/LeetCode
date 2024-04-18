class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        if ( i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == 0){
            return 1;
        }
        if (grid[i][j] == -1) {
            return 0;
        }
        grid[i][j] = -1;
        return (dfs(grid,i+1,j) + dfs(grid, i-1,j) + dfs(grid,i,j+1) + dfs(grid, i,j-1));
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (grid[i][j] == 1) {
                    ans+=dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};