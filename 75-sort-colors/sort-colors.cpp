class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, m = 0, h = n - 1;
        while(m <= h) {
            int it = nums[m];
            if(it == 0) {
                swap(nums[l++], nums[m++]);
            }
            else if (it == 1) {
                m++;
            }
            else {
                swap(nums[m], nums[h--]);
            }
        }
    }
};