class Solution {
public:
    void dfs(vector<vector<int>>& land, int i, int j, int &k, int &l) {
        k = max(k, i);
        l = max(l, j);
        land[i][j] = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int p = 0; p < 4; p++) {
            int nr = dr[p] + i;
            int nc = dc[p] + j;
            if(nr >= 0 && nr < land.size() && nc >= 0 && nc < land[0].size() && land[nr][nc] == 1) {
                dfs(land, nr, nc, k, l);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[0].size(); j++) {
                if(land[i][j] == 1) {
                    int k = 0, l = 0;
                    dfs(land, i, j, k, l);
                    ans.push_back({i, j, k, l});
                }
            }
        }
        return ans;        
    }
};