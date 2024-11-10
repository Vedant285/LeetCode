class Solution {
public:
    int solve(int n) {
        int pr = 1;
        while (n > 0) {
            if(n == 0) return 0;
            pr *= n % 10;
            n /= 10;
        }
        return pr;
    }
    int smallestNumber(int n, int t) {
        while (true) {
            if(solve(n) % t == 0) return n;
            n++;
        }
        return 0;
    }
};