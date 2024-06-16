class Solution {
public:
    int checkDays( int mid, vector<int>& nums){
        int days = 1;
        int sum = 0;

        for (auto it:nums) {
            if (it + sum > mid) {
                days++;
                sum = it;
            }
            else {
                sum += it;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(begin(weights), end(weights));
        int l = accumulate(begin(weights), end(weights),0);
        while (s <= l) {
            int mid = s + (l - s)/2;
            int d = checkDays(mid, weights);
            if (d <= days) {
                l = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return s;
    }
};