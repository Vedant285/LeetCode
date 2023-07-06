// Minimum Size Subarray Sum solution
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n=nums.length;
        int i=0,j=0,sum=0,result=Integer.MAX_VALUE;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                result=Math.min(result,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return result==Integer.MAX_VALUE?0:result;
    }
}
