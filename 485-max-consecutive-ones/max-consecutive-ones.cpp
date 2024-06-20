class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int temp = 0;
        for (auto it : nums) {
            if (it == 1) {
                temp++;
            }
            else {
                maxi = max(maxi, temp);
                temp = 0;
            }
        
        }
        return max(maxi, temp);
    }
};