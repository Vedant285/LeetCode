#define ll long long
int n;
class Solution {
    ll solve(int idx, vector<vector<int>>& arr, vector<ll>& dp) {
        if(idx >= n) {
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        ll nottake = solve(idx + 1, arr, dp);
        ll take = arr[idx][0] + solve(idx + arr[idx][1] + 1, arr, dp);
        return dp[idx] = max(nottake, take);
    }
    
public:
    long long mostPoints(vector<vector<int>>& arr) {
        n = arr.size();
        vector<ll>dp(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            ll nottake = dp[idx + 1];
            ll take = arr[idx][0] + (idx + arr[idx][1] + 1 < n? dp[idx + arr[idx][1] + 1] : 0);
            dp[idx] = max(nottake, take);
        }
        return dp[0];
    }
};