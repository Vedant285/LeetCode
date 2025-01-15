class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0), curr(n, 0);
        curr[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                int up = (i >= 1) ? prev[j] : 0;
                int left = (j >= 1) ? curr[j  - 1] : 0;
                curr[j] = up + left;
            }
            prev = curr;
        }

        return curr[n - 1];
    }
};