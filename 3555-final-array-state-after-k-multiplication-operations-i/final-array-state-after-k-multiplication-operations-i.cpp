class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = size(nums);
        for (int i = 0; i < k; i++) {
            auto mini = std::min_element(nums.begin(), nums.end());
            int miniInd = std::distance(nums.begin(), mini);
            
            nums[miniInd] = (*mini *= multiplier);
        }
        return nums;
    }
};