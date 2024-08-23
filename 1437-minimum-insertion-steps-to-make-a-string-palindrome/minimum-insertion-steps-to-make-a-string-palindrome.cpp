class Solution {
public:
    int solve(int i, int j, string s, string t) {
        if(i < 0 || j < 0) return 0;

        if(s[i] == t[j]) 
            return 1 + solve(i - 1, j - 1, s, t);

        return max(solve(i - 1, j, s, t), solve(i, j - 1, s, t));
    }
    int minInsertions(string s) {
        int n = s.size();
        string k = s;
        reverse(k.begin(), k.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(s[i - 1] == k[j - 1]) 
                    curr[j] = 1 + prev[j - 1];

                else curr[j] = max(prev[j],  curr[j - 1]);
            }
            prev = curr;
        }
        return n - prev[n];
    }
};