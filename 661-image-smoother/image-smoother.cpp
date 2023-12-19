class Solution {
public:
    vector<vector<int>>dir{
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0,0},{0,1},
        {1,-1},{1,0},{1,1}
    };
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=0;
                int number=0;
                for(auto it:dir){
                    int i_=i+it[0];
                    int j_=j+it[1];
                    if(i_>=0 && i_<n && j_>=0 && j_<m){
                        sum+=img[i_][j_];
                        number++;
                    }
                }
                ans[i][j]=sum/number;
            }
        }
        return ans;
    }
};