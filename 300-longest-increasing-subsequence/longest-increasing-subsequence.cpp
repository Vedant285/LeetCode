class Solution {
public:
    int lowerBounnd(vector<int>& temp, int t) {
        int n = temp.size();
        int s = 0, e = n - 1;
        int ans = n;
        while (s <= e) {
            int mid = (s + e)/2;
            if(temp[mid] >= t) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int s = 1;
        temp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                s++;
            }
            else {
                int ind = lowerBounnd(temp, nums[i]);
                temp[ind] = nums[i];
            }
        }
        return s;
    }
};