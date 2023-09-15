class Solution {
public:
    int n;
    int solve(int idx,vector<int>& prices,vector<vector<int>>&dp,int buy){
        if(idx==n)
            return 0;
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        int profit=0;
        if(buy==0){
            profit=max(-prices[idx]+solve(idx+1,prices,dp,1),0+solve(idx+1,prices,dp,0));
        }
        else{
            profit=max(prices[idx]+solve(idx+1,prices,dp,0),0+solve(idx+1,prices,dp,1));
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,prices,dp,0);
    }
};