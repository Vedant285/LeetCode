class Solution {
public:
    bool isPalin(int i, int j, string& s) {
        while (i < j) {
            if(s[i] != s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int mini = INT_MAX;

            for (int j = i; j < n; j++) {
                if(isPalin(i, j, s)) {
                    int cnt = 1 + dp[j + 1];
                    mini = min(mini, cnt);
                }
            }
            dp[i] = mini;
        }

        return dp[0] - 1;
    }
};