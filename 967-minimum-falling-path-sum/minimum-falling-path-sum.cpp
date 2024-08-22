class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //vector<vector<int>> dp (n, vector<int>(n));
        vector<int> prev(n, 0), curr(n, 0);
        for (int i = 0; i < n; i++) prev[i] = matrix[0][i];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++){

                int up = matrix[i][j] + prev[j];

                int leftDiag = matrix[i][j];
                if(j > 0) leftDiag += prev[j - 1];
                else leftDiag += (1e9);

                int rightDiag = matrix[i][j];
                if(j + 1 < n) rightDiag += prev[j + 1];
                else rightDiag += (1e9);

                curr[j] = min(up, min(leftDiag, rightDiag));
            }
            prev = curr;
        }
        int mini = *min_element(prev.begin(), prev.end());
        return mini;
    }
};