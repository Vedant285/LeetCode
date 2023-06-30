class Solution {
    int Row;
    int Col;
    Boolean dfs(int[][] grid,int i,int j){
        if(i<0 || j<0 || i>=Row || j>=Col  || grid[i][j]==1)return false;
        if(i==Row-1)return true;
        grid[i][j]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        for(int p=0;p<4;p++){
            int nr=i+dr[p];
            int nc=j+dc[p];
            if(dfs(grid,nr,nc))
                return true;
        }
        return false;
    }
    Boolean checkCross(int[][] cells,int r){
        int[][] grid=new int[Row][Col];
        for(int k=0;k<=r;++k){
            int x=cells[k][0]-1;
            int y=cells[k][1]-1;
            grid[x][y]=1;
        }
        for(int k=0;k<Col;k++){
            if( grid[0][k]==0 && dfs(grid,0,k)){
                return true;
            }
        }
        return false;
    }
    public int latestDayToCross(int row, int col, int[][] cells) {
        int l=0;
        int r=cells.length-1;
        int ans=0;
        this.Row=row;
        this.Col=col;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(checkCross(cells,mid)){
                ans=mid+1;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
    }
