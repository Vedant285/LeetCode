class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = size(s);
        string ans = s;
        for (int i = 0; i < n; i++) {
            ans[i] = s[(i + k) % n];
        }
        return ans;
    }
};