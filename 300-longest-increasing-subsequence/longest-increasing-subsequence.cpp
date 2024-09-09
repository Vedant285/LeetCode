class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int s = 1;
        temp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                s++;
            }
            else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return s;
    }
};