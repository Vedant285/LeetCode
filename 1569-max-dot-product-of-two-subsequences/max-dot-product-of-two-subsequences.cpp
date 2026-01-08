class Solution {
public:
    
    int solve(int i, int j, int n, int m, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>&dp) {
        if(i == n || j == m) return -1e9;
        if(dp[i][j] != -1) return dp[i][j];
        
        int val = nums1[i] * nums2[j];
        int takeij = solve(i + 1, j + 1, n, m, nums1, nums2, dp) + val;
        int takei = solve(i + 1, j, n, m, nums1, nums2, dp);
        int takej = solve(i, j + 1, n, m, nums1, nums2, dp);

        return dp[i][j] = max({val, takeij, takej, takei});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(0, 0, n, m, nums1, nums2, dp);
    }
};