class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int i = 0;
        int ans = INT_MAX;

        while (i < n){
            int sum = 0, j = i;

            while (j < n) {
                sum += nums[j];
                int len = j - i + 1;
                if(len >= l && len <= r && sum > 0) {
                    ans = min(ans, sum);
                }
                j++;
            }
            i++;
        }
        return ans == INT_MAX? -1: ans;
    }
};