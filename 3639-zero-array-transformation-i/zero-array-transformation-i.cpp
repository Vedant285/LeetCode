class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diff(n + 1, 0);
        
        for (auto it : queries) {
            int l = it[0];
            int r = it[1];
            diff[l]--;
            diff[r + 1]++;
        }
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if(nums[i] + diff[i] > 0) return 0;
        }
        return 1;
    }
};