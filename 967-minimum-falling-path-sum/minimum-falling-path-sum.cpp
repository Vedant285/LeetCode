class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp (n, vector<int>(n));
        for (int i = 0; i < n; i++) dp[0][i] = matrix[0][i];

        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < n; j++){

                int up = matrix[i][j] + dp[i - 1][j];

                int leftDiag = matrix[i][j];
                if(j > 0) leftDiag += dp[i - 1][j - 1];
                else leftDiag += (1e9);

                int rightDiag = matrix[i][j];
                if(j + 1 < n) rightDiag += dp[i - 1][j + 1];
                else rightDiag += (1e9);

                dp[i][j] = min(up, min(leftDiag, rightDiag));
            }
        }
        int mini = *min_element(dp[n- 1].begin(), dp[n - 1].end());
        return mini;
    }
};