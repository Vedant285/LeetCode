class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1, prev2 = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            curr =  prev1 + prev2;
            prev1 = prev2;
            prev2 = curr; 
        }
        return curr;
    }
};