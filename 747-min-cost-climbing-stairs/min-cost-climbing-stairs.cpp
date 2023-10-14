class Solution {
public:
    int dp[1001];
    int n;
    int solve(vector<int>& cost,int idx){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int a=cost[idx]+solve(cost,idx+1);
        int b=cost[idx]+solve(cost,idx+2);
        return dp[idx]=min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        n=cost.size();
        return min(solve(cost,0),solve(cost,1));
    }
};