class Solution {
public:
    int check(vector<int>&nums, int idx){
        int sum = 1;
        int cnt = 0;
        for (auto it : nums) {
            if (cnt + it <= idx) {
                cnt += it;
            } 
            else {
                cnt = it;
                sum ++;
            }
        }
        return sum;
    }

    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(begin(nums), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);
        
        while (s <= e) {
            int mid = (s + e)/2;
            if (check(nums, mid) > k) {
                s = mid + 1;
            } 
            else {
                e = mid - 1;
            }
        }
        return s;
    }
};