class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        if (n < 3)return 0;
        for (int i = 0; i < n - 2; i++) {
            if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) {
                cnt ++;
            }
        }
        return cnt;
    }
};