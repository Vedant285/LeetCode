class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        set<vector<int>>st;
        sort(begin(nums), end(nums));
        int i = 0;
        while (i < n) {
            int k = n - 1, j = i + 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    st.insert({nums[i], nums[j], nums[k]});
                    j++; k--;
                    //break;
                }
                else if(sum > 0) {
                    k--;
                }
                else j++;
            } 
            i++;
        }

        for (auto it : st) {
            ans.push_back(it);
        }

        return ans;
    }
};