class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        while (!pq.empty()) {
            int t = pq.top().first;
            //cout << t << " ";
            int idx = pq.top().second;
            pq.pop();
            if(nums[idx] != -1) {
                ans += t;
                if(idx + 1 < nums.size()) nums[idx + 1] = -1;
                if(idx - 1 >= 0) nums[idx - 1] = -1; 
            }
        }
        return ans;
    }
};