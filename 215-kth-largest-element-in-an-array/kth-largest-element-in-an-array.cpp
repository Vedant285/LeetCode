class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        //k %= n;
        k = n-k;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &it : nums) pq.push(it);
        while (!pq.empty()&& k != 0) {
            pq.pop();
            k--;
        }
        return pq.top();

    }
};