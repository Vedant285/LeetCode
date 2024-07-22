class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>>a;
        int i = 0;
        for(auto it : names) {
            a.push_back({heights[i], it});
            i++;
        }
        sort(a.rbegin(), a.rend());
        vector<string>ans;
        for (auto it : a) {
            string s = it.second;
            ans.push_back(s);
        }
        return ans;
    }
};