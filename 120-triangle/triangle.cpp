class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        //vector<vector<int>> dp(n, vector<int>(n));
        vector<int>prev(n, 0), curr(n, 0);
        for (int i = 0; i < n; i++) prev[i] = arr[n - 1][i];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {

                int a = arr[i][j] + prev[j];
                int c = arr[i][j] + prev[j + 1];
                curr[j] = min(a, c);
            }
            prev = curr;
        }
        return prev[0];
    }
};