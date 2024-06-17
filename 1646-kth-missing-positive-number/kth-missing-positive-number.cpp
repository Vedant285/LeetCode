class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s= 0, l = size(arr);
        while (s < l) {
            int mid = (s + l)/2;
            if (arr[mid] - (mid+1) < k) s = mid +1 ;
            else l = mid;
        }
        return s + k;
    }
};