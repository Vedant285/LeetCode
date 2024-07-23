class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        unordered_map<char, int>mp;
        int r = 0, l = 0;
        int n = size(s);
        while (r < n) {
            if (mp[s[r]] != 1) {
                maxi = max(maxi, r - l + 1);
                mp[s[r]] = 1;
                r++;
            }
            else {
                mp[s[l]] = 0;
                l++;
            }
        }
        return maxi;
    }
};