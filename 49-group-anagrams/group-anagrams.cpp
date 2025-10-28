class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for (auto it : strs) {
            string k = it;
            sort(k.begin(), k.end());
            mp[k].push_back(it);
        }    
        vector<vector<string>> ans;
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
