class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int cnt = 0, maxi = 0;;
        int n = size(weight);

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, weight[i]);

            if(weight[i] < maxi) {
                cnt++;
                maxi = 0;
            }
        }

        return cnt;
    }
};