class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n);
        int currMul = 1;
        for (int i = 0; i < n; i++) {
            pre[i] = currMul;
            currMul *= nums[i];
        }

        currMul = 1;
        for (int i = n - 1; i >= 0; i--) {
            pre[i] *= currMul;
            currMul *= nums[i];
        }
        return pre;
    }
};