class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        for (int i = 0; i < n;) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            while (i < n - 1 && e >= intervals[i + 1][0]) {
                e = max(e, intervals[i + 1][1]);                
                i++;
            }
            ans.push_back({s, e});
            i++;
        }
        return ans;
    }
};