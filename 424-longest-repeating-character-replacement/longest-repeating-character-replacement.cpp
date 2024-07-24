class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi = 0, l = 0, r = 0, arr[26] = {0};
        int maxf = 0;
        while(r < s.size()) {
            arr[s[r] - 'A'] ++;
            maxf = max(maxf, arr[s[r] - 'A']);
            if ((r - l + 1) - maxf > k) {
                arr[s[l] - 'A']--;
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};