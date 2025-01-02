class Solution {
public:
    bool check(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o'|| c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> cnt;
        
        for (auto it : words) {
            if(check(it[0]) && check(it.back())) {
                cnt.push_back(1);
            }
            else {
                cnt.push_back(0);
            }
        }
        vector<int> pre(cnt.size(), 0);
        pre[0] = cnt[0];

        for (int i = 1; i < cnt.size(); i++) {
            pre[i] = pre[i - 1] + cnt[i];
        }

        vector<int> ans;
        for (auto it : queries) {
            int l = it[0];
            int r = it[1];
            if(l == 0) {
                ans.push_back(pre[r]);
            }
            else {
                ans.push_back(pre[r] - pre[l - 1]);
            }
        }

        return ans;

    }
};