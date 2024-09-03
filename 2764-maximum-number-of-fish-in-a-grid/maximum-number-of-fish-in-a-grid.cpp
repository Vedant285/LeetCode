class Solution {
public:
    void solve(int i,int j,int &a,int &b,int &sum,int &ans,vector<vector<int>> &g){
        ans = max(ans,sum);
        if(i<0||j<0||i>=a||j>=b||g[i][j]==0){
            return;
        }
        sum += g[i][j];
        g[i][j] = 0;
        solve(i+1,j,a,b,sum,ans,g);
        solve(i,j+1,a,b,sum,ans,g);
        solve(i-1,j,a,b,sum,ans,g);
        solve(i,j-1,a,b,sum,ans,g);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int i,j,a = grid.size(),b = grid[0].size();
        int sum = 0;
        for(i = 0; i < a; i++){
            for(j = 0; j < b; j++){
                if(grid[i][j]){
                    sum = 0;
                    solve(i,j,a,b,sum,ans,grid);
                }
            }
        }
        return ans;
    }
};