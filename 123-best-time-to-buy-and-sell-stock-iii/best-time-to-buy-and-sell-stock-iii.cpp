// class Solution {
// public:
//     int n;
//     int solve(int i, int bos, int trans, vector<int>& prices) {
//         if(i == n || trans == 2) return 0;

//         if(bos == 0) {
//             return max(-prices[i]+ solve(i + 1, 1, trans, prices), solve(i + 1, 0, trans, prices));
//         }
//         return max(prices[i] + solve(i + 1, 0, trans + 1, prices), solve(i + 1, 1, trans, prices));
//     } 
//     int maxProfit(vector<int>& prices) {
//         n = prices.size();
//         return solve(0, 0, 0, prices);
//     }
// };

class Solution {
public:
    int n;
    int solve(int i, int bos, int trans, vector<int>& prices, vector<vector<vector<int>>>&dp) {
        if(i == n || trans == 2) return 0;
        if(dp[i][bos][trans] != -1) return dp[i][bos][trans];
        if(bos == 0) {
            return dp[i][bos][trans] = max(-prices[i]+ solve(i + 1, 1, trans, prices, dp), solve(i + 1, 0, trans, prices, dp));
        }
        return dp[i][bos][trans] = max(prices[i] + solve(i + 1, 0, trans + 1, prices, dp), solve(i + 1, 1, trans, prices, dp));
    } 
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(0, 0, 0, prices, dp);
    }
};