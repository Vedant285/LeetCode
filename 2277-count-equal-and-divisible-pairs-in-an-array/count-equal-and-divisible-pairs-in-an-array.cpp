class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
    int c=0;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=0 &&i!=j;j<nums.size();j++){
            if((i*j)%k==0 &&i<j && nums[i]==nums[j])
                c++;
        }
    }
    return c;        
    }
};