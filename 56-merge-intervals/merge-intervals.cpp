class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        int i =0, n = intervals.size();
        while (i < n) {
            int startTime = intervals[i][0];
            int endTime = intervals[i][1];
            
            while (i + 1 < n && intervals[i + 1][0] <= endTime) {
                endTime = max(endTime, intervals[i + 1][1]) ;
                i++;
            }
            ans.push_back({startTime, endTime});
            i++;
        }


        return ans;

    }
};