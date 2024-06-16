class Solution {
public:
    bool check(vector<int>&arr, int m, int k, int mid ) {
        int cnt = 0;
        int mini = 0;
        for (int i = 0 ; i < size(arr) ; i++) {
            if (arr[i] <= mid) {
                cnt ++;
            }
            else{
                mini += (cnt/k);
                cnt = 0;
            }
        }
        mini += (cnt/k);
        return m <= mini;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = size(bloomDay);
        if ((long long)m* (long long)k > n) {
            return -1;
        }
        int s = *min_element(begin(bloomDay), end(bloomDay));
        int l = *max_element(begin(bloomDay), end(bloomDay));
        int ans = INT_MAX;
        while (s <= l) {
            int mid = s + (l - s)/2;
            if(check(bloomDay, m, k, mid)) {
                l = mid - 1;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};