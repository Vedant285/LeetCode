//Longest Subarray of 1's After Deleting One Element solution 

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,result=0;
        int last_index=-1;
        while(j<nums.size()){
            if(nums[j]==0){
                i=last_index+1;
                last_index=j;
            }
            result=max(result,j-i);
            j++;
        }
        return result;
    }
};
