class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> p(26, {-1, -1});
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if(p[idx].first == -1) p[idx].first = i;
            p[idx].second = i; 
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            int l = p[i].first;
            int r = p[i].second;
            if(l == -1) continue;
            unordered_set<char> st;

            for (int j = l + 1; j < r; j++) {
                st.insert(s[j]);
            }
            ans += st.size();
        }

        return ans;

    }
};