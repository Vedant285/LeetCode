class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>>adj={
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {3,9,0},
        {},
        {1,7,0},
        {2,6},
        {1,3},
        {2,4}
    };
    int solve(int n,int i,vector<vector<int>>&dp){
        if(n==0){
            return 1;
        }
        if(dp[n][i]!=-1){
            return dp[n][i];
        }
        int res=0;
        for(auto it:adj[i]){
            res=(res+solve(n-1,it,dp))%mod;
        }
        return dp[n][i]=res;
    }
    int knightDialer(int n) {
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(10,-1));
        for(int i=0;i<10;i++){
            ans=(ans+solve(n-1,i,dp))%mod;
        }
        return ans;
    }
};