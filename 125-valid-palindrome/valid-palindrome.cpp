class Solution {
public:
    bool isPalindrome(string k) {
        int n = k.length();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && !isalnum(k[i])) {
                i++;
            }
            while (i < j && !isalnum(k[j])) {
                j--;
            }
            if (tolower(k[i]) != tolower(k[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};