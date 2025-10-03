class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long ans = LLONG_MAX;
        int n = nums.size();
        vector<bool> pre(n, 0);
        vector<long long>presum(n, 0);
        pre[0] = 1;

        presum[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            if(pre[i - 1] && nums[i - 1] < nums[i]) {
                pre[i] = 1;
            }
            else {
                break;
            }

        }

        for (int i = 1; i < n; i++) presum[i] = nums[i] + presum[i - 1];


        long long totsum = accumulate(nums.begin(), nums.end(), 0LL);

        vector<bool>suff(n, 0);

        suff[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            if(suff[i + 1] && nums[i] > nums[i + 1]) {
                suff[i] = 1;
            }
            else {
                break;
            }
        }

        bool checks= 0;
        for (int i = 0; i < n - 1; i++) {

            if(pre[i] && suff[i + 1]) {
                checks = 1;
                long long pres = presum[i];
                long long suffs = totsum - pres;

                ans = min(ans, abs(pres - suffs));

            }
        }
        return checks? ans: -1;
    }
};