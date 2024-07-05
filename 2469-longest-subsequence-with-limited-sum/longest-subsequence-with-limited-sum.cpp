class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),  nums.end());
        int n = nums.size();
        vector<int>prefSum(n, 0);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i-1] + nums[i];
        }
        int m = queries.size();
        vector<int>ans;
        for (auto it : queries) {
            int l = 0, h = n - 1;
            while (l <= h) {
                int mid = l + (h - l)/2;
                if (prefSum[mid] <= it) {
                    l = mid + 1;
                }
                else {
                    h = mid - 1;
                }
            }
            ans.push_back(l);
        }
        return ans;
    }
};