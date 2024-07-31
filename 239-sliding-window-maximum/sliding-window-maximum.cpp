class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = 0, n = size(nums), maxi = INT_MIN;
        vector<int> arr;
        multiset<int> st;
        while (r < n) {
            st.insert(nums[r]);
            if(r - l + 1 > k){
                l++;
            }
            else if (r - l + 1 == k) {
                arr.push_back(*st.rbegin());
                st.erase(st.find(nums[l]));
                l++;
            }
            r++;

        }
        return arr;
    }
};