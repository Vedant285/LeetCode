class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        int a1 = nums[0] + nums[1];
        int a2 = nums[1] + nums[2];
        int a3 = nums[2] + nums[0];
        
        if(a1 <= nums[2] || a2 <= nums[0] || a3 <= nums[1]) {
            return "none";
        }

        if(nums[0] != nums[1] && nums[1] != nums[2] && nums[2] != nums[0] ) {
            return "scalene";
        }

        return "isosceles";
        
    }
};