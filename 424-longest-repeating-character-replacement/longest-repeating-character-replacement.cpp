class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int l = 0, r = 0, n = s.size();
        int maxicnt = 0;
        while (r < n) {
            cnt[s[r]-'A']++;
            maxicnt = max(maxicnt, cnt[s[r]-'A']);
            if ((r - l + 1) - maxicnt > k) {
                cnt[s[l]-'A']--;
                l++;
            }
            
            r++;
        }
        return r - l;
    }
};