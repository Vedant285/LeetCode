class Solution {
public:
    int n;
    int solve(int idx,vector<int>& prices,vector<vector<vector<int>>>&dp,int buy,int cap){
        if(idx==n || cap==0)
            return 0;
        if(dp[idx][buy][cap]!=-1){
            return dp[idx][buy][cap];
        }
        int profit=0;
        if(buy==0){
            profit=max(-prices[idx]+solve(idx+1,prices,dp,1,cap),0+solve(idx+1,prices,dp,0,cap));
        }
        else{
            profit=max(prices[idx]+solve(idx+1,prices,dp,0,cap-1),0+solve(idx+1,prices,dp,1,cap));
        }
        return dp[idx][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,prices,dp,0,2);
    }
};