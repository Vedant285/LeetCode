#define ll long long

class Solution {
public:
    ll check(vector<int>& arr, ll mid) {
        ll cnt = 0;
        for (int i = 0 ; i < arr.size() ; i++) {
            cnt += ceil((double)arr[i]/mid);
        }
        return cnt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        ll s = 1, e = *max_element(piles.begin(), piles.end());
        while (s < e) {
            ll mid = s + (e - s) / 2;
            ll hours = check(piles, mid);
            if (hours > h) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
    }
};
