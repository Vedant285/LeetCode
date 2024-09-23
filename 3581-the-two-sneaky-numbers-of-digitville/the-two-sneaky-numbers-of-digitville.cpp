class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int>mp;
        for (auto it : nums) mp[it]++;
        vector<int>ans;
        for (auto [a, b] : mp) {
            if(b == 2) ans.push_back(a);
        }
        return ans;
    }
};