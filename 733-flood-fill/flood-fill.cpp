class Solution {
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int k){
        int n=image.size();
        int m=image[0].size();
        image[sr][sc]=color;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr=dr[i]+sr;
            int nc=dc[i]+sc;
            if(nr>=0 && nc>=0 && nr<n && nc<m && image[nr][nc]!=color && image[nr][nc]==k ){
                dfs(image,nr,nc,color,k);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        int k=image[sr][sc];
        dfs(image,sr,sc,color,k);
        return image;
    }
};