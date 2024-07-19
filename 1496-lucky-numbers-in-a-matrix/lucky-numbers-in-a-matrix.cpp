class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> rMini, cMaxi;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;
            for (int j = 0; j < m; j++) {
                mini = min(mini,matrix[i][j]);
            }
            rMini.push_back(mini);
        }
        for (int i = 0; i < m; i++) {
            int maxi = INT_MIN;
            for (int j = 0; j < n; j++) {
                maxi = max(maxi,matrix[j][i]);
            }
            cMaxi.push_back(maxi);
        }
        vector<int>ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == rMini[i] && matrix[i][j] == cMaxi[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};