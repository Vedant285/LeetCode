class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        string s = to_string(x);
        int n = size(s);
        for (int i = 0 ; i < size(s)/2 ; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
};