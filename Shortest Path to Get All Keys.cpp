class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<vector<int>>q;
        int total_count_keys=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@'){
                    q.push({i,j,0,0});
                }
                else if(grid[i][j]>='a' &&  grid[i][j]<='f'){
                    total_count_keys++;
                }
            }
        }
        int final_key=pow(2,total_count_keys)-1;
        int vis[n][m][final_key+1];
        memset(vis,0,sizeof(vis));
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int currx=node[0];
            int curry=node[1];
            int steps=node[2];
            int deci=node[3];
            if(deci==final_key)return steps;
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nr=currx+dr[i];
                int nc=curry+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!='#'){
                    char ch=grid[nr][nc];
                    if(ch>='A' && ch<='F'){
                        if(!vis[nr][nc][deci] && ((deci>>(ch-'A')))&1==1){
                            vis[nr][nc][deci]=1;
                            q.push({nr,nc,steps+1,deci});
                        }
                    }else if(ch>='a' && ch<='f'){
                        int nks=deci | (1<<(ch-'a'));
                        if(!vis[nr][nc][nks]){
                            vis[nr][nc][nks]=1;
                            q.push({nr,nc,steps+1,nks});
                        }
                    }else{
                        if(!vis[nr][nc][deci]){
                            vis[nr][nc][deci]=1;
                            q.push({nr,nc,steps+1,deci});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
