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
        vector<vector<int>>prev(3, vector<int>(3, 0)), curr(3, vector<int>(3, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int bos = 1; bos >= 0; bos--) {
                for (int trans = 1; trans >= 0; trans--) {
                    if(bos == 0) {
                        curr[bos][trans] = max(-prices[i]+ prev[1][trans], prev[0][trans]);
                    }
                    else curr[bos][trans] = max(prices[i] + prev[0][trans + 1], prev[1][trans]);
                }
                prev = curr;
            }
        }
        
        return prev[0][0];
    }
};