class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>ans;

        for (int i = 0; i < n; i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            //int j  = i + 1;
            while (i < n - 1 && e >= intervals[i + 1][0]) {
                e = max(e, intervals[i + 1][1]);
                i++;
            }
                ans.push_back({s, e});
            
        }

        return ans;

    }
};