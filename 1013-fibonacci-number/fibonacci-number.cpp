class Solution {
public:
    int fib(int n) {
        int curr = 1;
        int prev = 0;
        for (int i = 1 ; i <= n ; i++) {
            int ans = prev + curr;
            prev = curr;
            curr = ans;
        }
        return prev;
    }
};