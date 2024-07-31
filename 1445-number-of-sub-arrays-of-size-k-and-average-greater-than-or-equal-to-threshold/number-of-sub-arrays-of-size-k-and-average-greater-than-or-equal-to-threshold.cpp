class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0, r = 0, n = arr.size(), cnt = 0, ans = 0;

        while (r < n) {
            cnt += arr[r];
            while (r - l + 1 > k && l <= r) {
                cnt -= arr[l];
                l++;
            }
            if(r - l + 1 == k && (cnt/k) >= threshold) {
                ans++;
            }
            r++;
        }

        return ans;
    }
};