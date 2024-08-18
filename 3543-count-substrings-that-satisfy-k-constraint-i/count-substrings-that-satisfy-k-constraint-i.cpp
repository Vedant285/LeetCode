class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a= 0 , b = 0;
            for (int j = i; j < n; j++) {
                if(s[j] == '0') a++;
                else b++;
                if (a <= k || b <= k)ans++;
            }
        }
        return ans;
    }
};