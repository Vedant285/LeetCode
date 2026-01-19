class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> pre(n+1 , vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pre[i][j] = mat[i - 1][j - 1] + pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1]; 
            }
        }

        int ans = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <=m ; j++) {
                int k = ans + 1;
                if(i >= k && j >= k) {
                    int currsum = pre[i][j] - pre[i - k][j] - pre[i][j - k] + pre[i - k][j - k];
                    if(currsum <= threshold) ans++;
                }
            } 
        }

        return ans;
    }
};