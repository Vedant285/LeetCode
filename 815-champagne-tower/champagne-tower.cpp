class Solution {
public:
    double solve(int poured,int i,int j,vector<vector<double>>&dp){
        if(i<j || i<0 || j<0)
            return 0.0;
        if(i==0 && j==0)
            return poured;
        if(dp[i][j]>-1.0)
            return dp[i][j];
        double left_take=(solve(poured,i-1,j-1,dp)-1)/2;
        if(left_take<0.0)
            left_take=0.0;
        double right_take=(solve(poured,i-1,j,dp)-1)/2;
        if(right_take<0.0)
            right_take=0.0;
        return dp[i][j]=left_take+right_take;

    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(query_row+1,vector<double>(query_glass+1,-1));
        return min(1.0,solve(poured,query_row,query_glass,dp));
    }
};