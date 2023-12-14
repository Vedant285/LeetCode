class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        vector<int>r(m,0),c(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    r[i]++;
                    c[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int onesRowi=r[i];
                int onesColj=c[j];
                int zerosRowi=m-onesRowi;
                int zerosCol=n-onesColj;
                ans[i][j] = onesRowi + onesColj - zerosRowi - zerosCol;
            }
        }
        return ans;
    }
};