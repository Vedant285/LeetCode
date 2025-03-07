class Solution {
public:
    vector<int> closestPrimes(int left, int right) {

        vector<bool> prime(right+1, 1);
        prime[0] = prime[1] = 0;
        for (int i = 2; i*i <= right; i++) {
            if(prime[i] == 1) {
                for (int j = i*i; j <= right; j+=i) {
                    prime[j] = 0;
                }
            }
        }
        int prev = INT_MAX;
        int l = -1;
        vector<int>ans(2, -1);

        for (int i = left; i <= right; i++) {
            if(prime[i] == 1) {
                
                if(l != -1 ) {
                    int diff = i - l;
                    if(diff < prev) {
                        prev = diff;
                        ans[0] = l;
                        ans[1] = i;
                    }
                }
                l = i;
            }
        }
        if(l == -1) {
            return {-1, -1};
        }
        return ans;
    }
};