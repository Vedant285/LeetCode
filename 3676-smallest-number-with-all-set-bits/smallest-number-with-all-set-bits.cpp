class Solution {
public:
    int smallestNumber(int n) {
        
        for (int i = 0; i <= n; i++) {
            int p = pow(2, i);
            if(p - 1 >= n) return p - 1;
        }
        return -1;
    }
};