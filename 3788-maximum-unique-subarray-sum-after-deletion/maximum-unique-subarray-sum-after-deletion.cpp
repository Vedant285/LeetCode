class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> st;
        for (auto it : nums) {
            if(it >= 0) {
                st.insert(it);
            }
        }
        if(st.empty()) {
            return *max_element(nums.begin(), nums.end());
        }
        int sum = 0;
        for (auto it : st) {
            sum += it;
        }

        return sum;
    }
};