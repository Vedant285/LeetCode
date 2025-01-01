class Solution {
public:
    int maxScore(string s) {
        int one = 0;
        for (auto it : s) {
            if( it == '1') one++;
        }
        int n = s.size();
        int ans = 0;
        int z = 0;
        for (int i = 1; i < n; i++) {
            if(s[i - 1] == '0') {
                z++;
                int t = one + z;
                ans = max(ans, t);
            }
            else {
                one--;
                int t = one + z;
                ans = max(ans, t);
            }
        }
        return ans;
    }
};