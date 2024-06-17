class Solution {
public:
    int reverse(int x) {
        long  ans = 0;
        int temp = x;
        while (temp) {
            int lstD = temp % 10;
            ans = ans*10 +(lstD);
            temp /= 10;
        }
        if (ans > INT_MAX  || ans < INT_MIN) return 0;

        return ans;
    }
};