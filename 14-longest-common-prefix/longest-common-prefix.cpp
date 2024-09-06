class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string s = strs[0], e = strs[n - 1];
        for (int i = 0; i < min(s.size(), e.size()); i++) {
            if(s[i] != e[i]) return ans;
            ans += s[i];
        }
        return ans;
    }
};