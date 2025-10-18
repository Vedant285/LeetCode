class Solution {
public:
    double myPow(double x, int n) {
        double base = 1.0;
        long long t = n;

        if(n < 0) {
            x = 1/x;
            t = -t;
        }

        while (t > 0) {
            if (t & 1) 
                base *= x;
            
            x *= x;
            t >>= 1;
        }

        return base;
    }
};