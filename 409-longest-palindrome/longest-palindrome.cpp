class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for (auto it:s) {
            mp[it] ++;
        }
        int even = 0;
        int ans = 0;
        for (auto it:mp) {
            if (it.second %2 == 0) {
                ans += it.second;
            }
            else {
                even = 1;
                ans += it.second-1;
            }
        }
        return ans + even;
    }
};