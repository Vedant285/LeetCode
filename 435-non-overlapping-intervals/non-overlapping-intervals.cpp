class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(),[&](vector<int>& a1, vector<int>& a2) {
            return a1[1] < a2[1];
        });
        int cnt = 0, n = arr.size();
        int fire = INT_MIN;
        for (auto it : arr) {
            if (it[0] >= fire) {
                cnt++;
                fire = it[1];
            }
        }
        return n - cnt;
    }
};