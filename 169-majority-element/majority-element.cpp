class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=-1,idx=0;
        for(auto it:nums){
            if(idx==0){
                idx=1;
                ele=it;
            }
            else if(it==ele){
                idx++;
            }
            else{
                idx--;
            }
        }
        return ele;
    }
};