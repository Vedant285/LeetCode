class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, c = 0;
        s.push_back('1');
        for (int i = 0; i < size(s) - 1; i++) {
            if(s[i] == '0' && s[i + 1] == '1') {
                ans += c;
            }
            else if(s[i] == '1') {
                c++;
            }
        }
        return ans;
    }
};