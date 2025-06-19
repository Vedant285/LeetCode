class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int cnt = 1;
        int mini = nums[0];
        for (int i = 1; i < nums.size() ; i++) {
            if(nums[i] - mini > k) {
                cnt++;
                mini = nums[i];
            }
        }

        return cnt;   
    }
};