class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>st;
        for (unsigned int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];
            if(st.find(temp) != st.end()) return {static_cast<int>(i), st[temp]};
            st[nums[i]] = i;
        }
        return {};
    }
};