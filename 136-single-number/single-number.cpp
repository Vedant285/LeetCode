class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1=0;
        for(auto it:nums){
            xor1^=it;
        }
        return xor1;
    }
};