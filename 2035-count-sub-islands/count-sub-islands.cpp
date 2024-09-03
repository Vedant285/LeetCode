class Solution {
bool c=1;
     void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int n,int m,int i,int j){
        if(grid1[i][j]==0)c=0;
        grid2[i][j]=0;
        int dc[]={1,0,-1,0,1};
        for(int l=0;l<4;l++)
        {
            int nr=i+dc[l];
            int nc=j+dc[l+1];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid2[nr][nc]==1)
            dfs(grid1,grid2,n,m,nr,nc);
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int ans=0;
        int n=grid1.size();
        int m=grid1[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1)
                {
                    dfs(grid1,grid2,n,m,i,j);
                    if(c)
                        ans++;
                    c=1;
                }
            }
        }
        return ans;        
    }
};