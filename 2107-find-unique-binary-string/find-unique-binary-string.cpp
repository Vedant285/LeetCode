class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";
        for(int i=0;i<nums.size();i++){
            char ch=nums[i][i];
            ans+=(ch=='0'?'1':'0');
        }
        return ans;
    }
};