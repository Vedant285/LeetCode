#define ll long long
class Solution {
public:
    bool check(vector<int>& nums, int m, int k, int idx) {
        ll sum = 0;
        ll ans = 0;
        for (int i = 0 ; i < nums.size(); i++) {
            if (nums[i] <= idx) {
                sum ++;
            }
            else {
                ans += (sum / k);
                sum = 0;
            }
        }
        ans += (sum  / k);
        return ans >= m;   
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((ll)k * (ll)m > n) {
            return -1;
        }
        ll s = *min_element(bloomDay.begin(), bloomDay.end());
        ll l = *max_element(bloomDay.begin(), bloomDay.end());
        while( s <= l) {
            ll mid = s + ( l - s )/2;
            if (check(bloomDay, m, k, mid) ) {
                l = mid -1 ;
            }
            else {
                s = mid + 1;
            }
        }
        
        return s;
    }
};