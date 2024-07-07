class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt = 0;
        sort(nums.begin(), nums.end());
        int s = 0, e = nums.size() - 1;
        while (s < e) {
            if (nums[s] + nums[e] == k) {
                s ++;
                e--;
                cnt ++;
            }
            else if (nums[s] + nums[e] < k) {
                s++;
            }
            else {
                e--;
            }
        }
        return cnt;
    }
};