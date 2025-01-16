class Solution {
public:
    bool canPartition(vector<int>& arr) {
        long long s = accumulate(arr.begin(), arr.end(), 0);
        if(s %2 != 0) return 0;
        s /= 2;
        int n = arr.size();
        vector<int>prev(s + 1, 0), curr(s + 1, 0);

        for (int sum = 0; sum <= s; sum++) {
            if(arr[0] == sum) prev[sum] = 1;
        }


        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= s; sum++) {
                int take = (arr[i] <= sum) ? prev[sum - arr[i]]: 0;
                int nottake = prev[sum];
                curr[sum] = take || nottake;
            }
            prev = curr;
        }
        return prev[s];
    }
};