class Solution {
public:
    bool check(string s1, string s2) {
        if(s1.size() + 1 != s2.size()) return 0;
        int j = 0, i = 0;
        while(i < s1.size() && j < s2.size()) {
            if(s1[i] == s2[j]) {
                i++; 
            }
            j++;
        }
        return i == s1.size();
    };
    int longestStrChain(vector<string>& words) {
        int n = size(words);
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), [&](string &s1, string &s2) {
            return s1.size() < s2.size();
        });
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if(check(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxi = max(maxi, dp[i]);
                }
            }
        }
        return maxi;
    }
};