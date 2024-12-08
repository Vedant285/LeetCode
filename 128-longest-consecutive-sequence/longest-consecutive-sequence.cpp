class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int>st;
        for (auto it : nums) st[it]++;

        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            int cnt = 0;
            if(st.find(curr - 1) != st.end()) continue;
            while (st.find(curr) != st.end()) {
                cnt++;
                curr++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};