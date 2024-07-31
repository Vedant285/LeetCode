class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [&](vector<int>& a1, vector<int>& a2) {
            return a1[1] < a2[1];
        });
        int ans = 0;
        int laseEnd = INT_MIN;
        for (int i = 0; i < pairs.size() ; i++) {
            if(pairs[i][0] > laseEnd) {
                ans++;
                laseEnd = pairs[i][1];
            }
        }
        return ans;
    }
};