class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int a = 1, b = 1;
        for (int i = 1; i < n; i++) {
            
            if(nums[i] > nums[i - 1]){a++, b= 1;}
            else if(nums[i] < nums[i - 1]) {b++, a = 1;}
            else {a = 1, b = 1;}

            ans = max({ans, a, b});
        }
        return ans;
    }
};