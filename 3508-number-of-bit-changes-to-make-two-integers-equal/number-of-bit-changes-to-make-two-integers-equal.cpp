class Solution {
public:
    int minChanges(int n, int k) {
        if ((n&k) == k) 
        return __builtin_popcount(n ^ k);
        
        return -1;
    }
};