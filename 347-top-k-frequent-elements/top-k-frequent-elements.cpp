class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for (auto it : nums) {
            mp[it]++;
        }
        int n = nums.size();
        vector<vector<int>>temp(n + 1);
        for (auto it : mp) {
            temp[it.second].push_back(it.first);
        }
        vector<int>ans;
        for (int i = n; i >= 0; i-- ) {
            if(ans.size() >= k) return ans;
            if(!temp.empty()) {
                ans.insert(ans.end(), temp[i].begin(), temp[i].end());
            }
        }
        return ans;

    }
};