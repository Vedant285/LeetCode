class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int t = i;
        while (i < n - 1 && nums[i] < nums[i + 1]) {
            i++;
        }
        if(i == n - 1 || t == i) return false;

        t = i;
        while (i < n - 1 && nums[i] > nums[i + 1]) {
            i++;
        }

        if(i == n - 1 || t == i) return 0;

        while (i < n - 1 && nums[i] < nums[i + 1]) {
            i++;
        }

        if(i == n - 1) return 1;
        return 0;

    }
};