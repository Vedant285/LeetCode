class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int l = 0, r = 0, n = s.size();
        int maxLen = 0;
        int maxicnt = 0;
        while (r < n) {
            cnt[s[r]-'A']++;
            maxicnt = max(maxicnt, cnt[s[r]-'A']);
            while (l <= r && (r - l + 1) - maxicnt > k) {
                cnt[s[l]-'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};