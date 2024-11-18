class Solution {
public:
    int reverse(int tt) {
        long long ans = 0;
        int x = abs(tt);
        while (x > 0) {
            int last = x % 10;
            ans = (ans * 10) + last;
            x /= 10;
        } 
        if(ans >= INT_MAX || ans == INT_MIN) return 0;

        return tt > 0 ? ans : -ans;
    }
};